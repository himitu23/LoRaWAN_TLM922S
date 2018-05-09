/***************
 *
 * OTAA_Sample - TLM922S-P01A join OTAA sample for Arduino
 *
 * target architectures: Atmel AVR (ATmega 328P, 1284P and other)
 *
 * release site: https://github.com/askn37/LoRaWAN_TLM922S
 * maintainer: askn https://twitter.com/askn37
 *
 */

#include <Arduino.h>
#include "LoRaWAN_TLM922S.h"

#define TX_PIN		12			// D12 O to I TLM_MISO/RX(12)
#define RX_PIN		11			// D11 I to O TLM_MOSI/TX(11)
#define WAKE_PIN	7			// D7  O to I TLM_INT2/WakeUp/~Sleep(7)

#define LORAWAN_BAUD	9600
#define CONSOLE_BAUD	9600

LoRaWAN_TLM922S LoRaWAN(RX_PIN, TX_PIN);

void setup (void) {
    bool f;

    // コンソール出力を有効化
    while (!Serial);
    Serial.begin(CONSOLE_BAUD);
    Serial.println(F("Startup"));

    // LoRaWANモジュールに接続し
    // エコーバック表示を有効化
    LoRaWAN.begin(LORAWAN_BAUD);
    LoRaWAN.setEchoThrough(ECHO_ON);

    // Wakeupピンを上げてスリープ解除
    pinMode(WAKE_PIN, OUTPUT);
    digitalWrite(WAKE_PIN, HIGH);

    // 準備ができるのを待つ
    while (!LoRaWAN.getReady()) {
        Serial.println(F("=getReady:0"));
        delay(1000);
    }

    // リセットコマンドを試す
    // 成功すれば真
    f = LoRaWAN.reset();
    Serial.print(F("=reset:")); Serial.println(f);

    // // ボーレート設定を試す
    // // 結果は得られないが
    // // 実行後は wakeUp()を使う
    // LoRaWAN.setBaudRate(LORAWAN_BAUD);
    // LoRaWAN.begin(LORAWAN_BAUD);
    // LoRaWAN.wakeUp();

    // ファームウェアバージョン文字列取得
    // 成功すれば真
    f = LoRaWAN.getVersion();
    Serial.print(F("=getVersion:")); Serial.println(f);
    printResult();
    if (f) {
        Serial.print(F("=isData:")); Serial.println(LoRaWAN.isData());
        if (LoRaWAN.isData()) {
            Serial.print(F("=getData:["));
            Serial.print(LoRaWAN.getData());
            Serial.println(']');
        }
    }

    // DevEUI文字列取得
    // 成功すれば真
    f = LoRaWAN.getDevEUI();
    Serial.print(F("=getDevEUI:")); Serial.println(f);
    printResult();
    if (f) {
        Serial.print(F("=isData:")); Serial.println(LoRaWAN.isData());
        if (LoRaWAN.isData()) {
            Serial.print(F("=getData:["));
            Serial.print(LoRaWAN.getData());
            Serial.println(']');
        }
    }

    // 現在のDevAddr文字列取得
    // 成功すれば真
    f = LoRaWAN.getDevAddr();
    Serial.print(F("=getDevAddr:")); Serial.println(f);
    if (LoRaWAN.isData()) {
        Serial.print(F("=getData:["));
        Serial.print(LoRaWAN.getData());
        Serial.println(']');
    }

    // joinの前に、工場出荷時リセット
    // 成功すれば真
    f = LoRaWAN.factoryReset();
    Serial.print(F("=factoryReset:")); Serial.println(f);

    // エコーバック有効化（ON=工場出荷時デフォルト）
    // 成功すれば真
    f = LoRaWAN.setEcho(ECHO_ON);
    Serial.print(F("=setEcho:")); Serial.println(f);

    // joinが成功するまでループ
    do {
        if (!f) delay(2000);

        // OTAAでjoinする
        // 第1プロンプト結果が Okなら真
        f = LoRaWAN.join(JOIN_OTAA);
        Serial.print(F("=join:")); Serial.println(f);
        if (f) {
            // 第2プロンプトを待つ
            // 結果が acceptedなら真
            f = LoRaWAN.joinResult();
            Serial.print(F("=joinResult:")); Serial.println(f);
        }
        printResult();
    } while (!f);

    // ADRモード設定を調べる
    // onなら真
    f = LoRaWAN.getAdr();
    Serial.print(F("=getAdr:")); Serial.println(f);
    printResult();
    if (!f) {
        // ADRをオンにする
        // 成功なら真
        f = LoRaWAN.setAdr(ADR_ON);
        Serial.print(F("=setAdr:")); Serial.println(f);
        printResult();
    }

    // join後のDevAddr文字列取得（成功すれば変わっている）
    // 成功すれば真
    f = LoRaWAN.getDevAddr();
    Serial.print(F("=getDevAddr:")); Serial.println(f);
    if (LoRaWAN.isData()) {
        Serial.print(F("=getData:["));
        Serial.print(LoRaWAN.getData());
        Serial.println(']');
    }

    // DR値を設定する
    // 成功なら真
    f = LoRaWAN.setDataRate(3);
    Serial.print(F("=setDataRate:")); Serial.println(f);

    // DR値を取得する
    // 成功なら真
    uint8_t v = LoRaWAN.getDataRate();
    Serial.print(F("=getDataRate:")); Serial.println(v);

    // lorawan設定を保存する（DR値など）
    // 成功なら真
    f = LoRaWAN.loraSave();
    Serial.print(F("=loraSave:")); Serial.println(f);

    // module設定を保存する（baudrateなど）
    // 成功なら真
    f = LoRaWAN.modSave();
    Serial.print(F("=modSave:")); Serial.println(f);
}

void loop (void) {
    bool f;

    // // リンクチェックを要求する
    // // 成功なら真
    // f = LoRaWAN.setLinkCheck();
    // Serial.print(F("=setLinkCheck:")); Serial.println(f);

    // txコマンドを confirmモードで準備する
    // 成功すれば真
    if (!LoRaWAN.tx(TX_CNF, 1)) { return; }

    // 送信データを準備する
    LoRaWAN.txData("cafe");     // これは LoRaWAN.write("cafe") でも同じ
    LoRaWAN.txData(micros());   // uint32_t型をHEX8桁で準備

    // 送信を実行
    // 第1プロンプト結果が Okなら真
    f = LoRaWAN.txRequest();
    Serial.print(F("=tx:")); Serial.println(f);
    if (f) {
        // 第2プロンプトを待つ
        // 結果が tx_okなら真
        f = LoRaWAN.txResult();
        Serial.print(F("=txResult:")); Serial.println(f);

        // リンクチェックが得られたなら真（ucnfでもダウンリンク発生）
        Serial.print(F("=isLinkCheck:")); Serial.println(LoRaWAN.isLinkCheck());
        if (LoRaWAN.isLinkCheck()) {
            // マージン値とゲートウェイ数を取得
            Serial.print(F("=getMargin:")); Serial.println(LoRaWAN.getMargin());
            Serial.print(F("=getGateways:")); Serial.println(LoRaWAN.getGateways());
        }

        // rxダウンリンクデータが得られたなら真
        Serial.print(F("=isData:")); Serial.println(LoRaWAN.isData());
        if (LoRaWAN.isData()) {
            // rxポート番号とバイナリデータを取得
            Serial.print(F("=getRxPort:")); Serial.println(LoRaWAN.getRxPort());
            Serial.print(F("=getData:["));
            Serial.print(LoRaWAN.getData());    // HEXからBINに変換済
            Serial.println(']');
        }
    }
    printResult();

    // Sleepピンを下げて、スリープ可能にする
    digitalWrite(WAKE_PIN, LOW);

    // 無制限ディープスリープを実行
    // 成功なら真
    f = LoRaWAN.sleep(0);
    Serial.println();
    Serial.print(F("=sleep:")); Serial.println(f);

    // 任意のキー入力がコンソールにあるまで待機
    Serial.println();
    Serial.println(F("[Push any key wait]"));
    while(!Serial.available());
    while(Serial.available()) Serial.read();

    // Wakeupピンを上げてスリープ解除
    // 成功なら真
    digitalWrite(WAKE_PIN, HIGH);
    f = LoRaWAN.wakeUp();
    Serial.print(F("=wakeUp:")); Serial.println(f); 

    // 以後繰り返し  
}

// リザルトを取得して番号と名前を表示する
void printResult (void) {
    uint8_t ps = LoRaWAN.getResult();
    Serial.print(F("=getResult:"));
    switch (ps) {
        case PS_NOOP       : Serial.println(F("0:PS_NOOP")); return;
        case PS_READY      : Serial.println(F("1:PS_READY")); return;
        case PS_PREFIX     : Serial.println(F("2:PS_PREFIX")); return;
        case PS_ENDRESET   : Serial.println(F("3:PS_ENDRESET")); return;
        case PS_MODRESET   : Serial.println(F("4:PS_MODRESET")); return;
        case PS_DEMODMARG  : Serial.println(F("5:PS_DEMODMARG")); return;
        case PS_NBGATEWAYS : Serial.println(F("6:PS_NBGATEWAYS")); return;
        case PS_RX         : Serial.println(F("7:PS_RX")); return;
        case PS_OK         : Serial.println(F("8:PS_OK")); return;
        case PS_TXOK       : Serial.println(F("10:PS_TXOK")); return;
        case PS_ACCEPTED   : Serial.println(F("11:PS_ACCEPTED")); return;
        case PS_JOINED     : Serial.println(F("12:PS_JOINED")); return;
        case PS_ADVANCE    : Serial.println(F("13:PS_ADVANCE")); return;
        case PS_ON         : Serial.println(F("14:PS_ON")); return;
        case PS_OFF        : Serial.println(F("15:PS_OFF")); return;
        case PS_INVALID    : Serial.println(F("16:PS_INVALID")); return;
        case PS_UNKOWN     : Serial.println(F("17:PS_UNKOWN")); return;
        case PS_ERR        : Serial.println(F("18:PS_ERR")); return;
        case PS_UNSUCCESS  : Serial.println(F("19:PS_UNSUCCESS")); return;
        case PS_UNJOINED   : Serial.println(F("20:PS_UNJOINED")); return;
        case PS_INVDLEN    : Serial.println(F("21:PS_INVDLEN")); return;
        case PS_KEYNOTINIT : Serial.println(F("22:PS_KEYNOTINIT")); return;
        case PS_NOFREECH   : Serial.println(F("23:PS_NOFREECH")); return;
        case PS_BUSY       : Serial.println(F("24:PS_BUSY")); return;
        case PS_NOTJOINED  : Serial.println(F("25:PS_NOTJOINED")); return;
        case PS_PASSWORDERR: Serial.println(F("26:PS_PASSWORDERR")); return;
        default:
            Serial.print(ps, DEC);
            Serial.println(F(":???"));
    }
}

// end of code
