/*
   Typical pin layout used:
   -----------------------------------------------------------------------------------------
               MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino
               Reader/PCD   Uno/101       Mega      Nano v3    Leonardo/Micro   Pro Micro
   Signal      Pin          Pin           Pin       Pin        Pin              Pin
   -----------------------------------------------------------------------------------------
   RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST
   SPI SS      SDA(SS)      10            53        D10        10               10
   SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
   SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
   SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15
*/

#include <Adafruit_NFCShield_I2C.h>

#define IRQ 6 // this trace must be cut and rewired!
#define RESET 8

Adafruit_NFCShield_I2C nfc(IRQ, RESET);

uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 }; // Buffer to store the returned UID
uint8_t uidLength; // Length of the UID (4 or 7 bytes depending on ISO14443A card type)
uint32_t versiondata;

void setup() {
  Serial.begin(115200);    // Initialize serial communications with the PC
  while (!Serial);      // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  nfc.begin();          // Init SPI bus
  versiondata = nfc.getFirmwareVersion();
  if (! versiondata) {
    Serial.print(F("Didn't find PN53x board"));
    while (1); // halt
  }
  // Got ok data, print it out!
  Serial.print(F("Found chip PN5")); Serial.println((versiondata>>24) & 0xFF, HEX);
  Serial.print(F("Firmware ver. ")); Serial.print((versiondata>>16) & 0xFF, DEC);
  Serial.print('.'); Serial.println((versiondata>>8) & 0xFF, DEC);
  
  // configure board to read RFID tags
  nfc.SAMConfig();
  
  //enable timeout waiting for cards
  nfc.setPassiveActivationRetries(50);
  Serial.println(F("Arduino Amiibo writer. Put your NFC-tag to the reader"));
}

void loop() {
  // Look for new cards
  if ( ! nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength)) {
    return;
  }

  // Select one of the cards
//  if ( ! mfrc522.PICC_ReadCardSerial()) {
//    return;
//  }

  // hexdump -v -e " 4/1 \"0x%02X, \" \"\n\"" Chibi-Robo.encoded.bin
  byte pages          = 135;
  byte dataBlock[]    = {

  //    >>> Paste your dump here <<<
0x04, 0x9d, 0x45, 0x54,
0x42, 0x40, 0x3e, 0x80,
0xbc, 0x48, 0x00, 0x00,
0xf1, 0x10, 0xff, 0xee,
0xa5, 0x00, 0x00, 0x00,
0x70, 0xa0, 0x10, 0x12,
0x0c, 0xc0, 0x81, 0xad,
0xc5, 0x74, 0x78, 0xe2,
0xca, 0xc6, 0x04, 0xc1,
0xc1, 0x17, 0x3d, 0x65,
0x21, 0xb7, 0x0e, 0x61,
0x9b, 0x6e, 0xc0, 0x77,
0x3e, 0xf7, 0x9b, 0xd5,
0x3e, 0x30, 0xcf, 0x8d,
0x34, 0xcd, 0xbd, 0x78,
0x99, 0x21, 0x49, 0x61,
0x67, 0x79, 0x3f, 0xda,
0x75, 0xf4, 0xd7, 0x6b,
0x78, 0x47, 0x04, 0xb9,
0x73, 0x9a, 0x29, 0x04,
0x23, 0x70, 0x00, 0x98,
0x00, 0x05, 0x00, 0x00,
0x03, 0x73, 0x01, 0x02,
0x0d, 0x12, 0x97, 0x06,
0x73, 0xf5, 0x7a, 0x05,
0x5f, 0xb3, 0x16, 0x7c,
0xc5, 0x13, 0x7f, 0xfe,
0x11, 0xc7, 0x49, 0x7d,
0x05, 0xf2, 0x43, 0x7c,
0xa5, 0x8b, 0xbc, 0x11,
0x20, 0xf3, 0x26, 0xab,
0xba, 0xa1, 0xdc, 0x7d,
0xf9, 0x30, 0xcb, 0xa5,
0x39, 0x57, 0xb2, 0x1a,
0x30, 0xa7, 0x93, 0x8d,
0xfa, 0xf8, 0x44, 0xbd,
0x95, 0x2f, 0xa7, 0xa8,
0xea, 0x75, 0xaf, 0x71,
0x10, 0x70, 0x15, 0x68,
0x66, 0xba, 0x3a, 0xf4,
0x99, 0x6c, 0x96, 0x95,
0x0a, 0xbe, 0x7e, 0xc0,
0xa1, 0xe7, 0xfd, 0xea,
0x35, 0x62, 0xe5, 0x35,
0x8b, 0x2d, 0x88, 0xee,
0xd1, 0x66, 0x96, 0x1c,
0xce, 0x8b, 0x34, 0x44,
0xc9, 0x4f, 0xb8, 0x41,
0x9b, 0xb8, 0xd6, 0xf3,
0x23, 0xaa, 0x70, 0xce,
0x55, 0x16, 0xe6, 0x41,
0xb5, 0x24, 0x9b, 0xc9,
0x76, 0xb5, 0xbe, 0xcd,
0x07, 0x4d, 0xa6, 0xf8,
0x83, 0xa8, 0xcd, 0x71,
0xf7, 0xb0, 0xf1, 0x8f,
0x64, 0xa9, 0xe6, 0xda,
0xe3, 0xe3, 0xbc, 0xae,
0xfc, 0xae, 0xd7, 0x07,
0x80, 0x97, 0xd7, 0xa0,
0xdc, 0xd3, 0xfd, 0x64,
0x22, 0xf9, 0x9e, 0x66,
0xbf, 0x50, 0x2a, 0x06,
0x97, 0x3b, 0xcb, 0x6f,
0x97, 0x92, 0x2c, 0xf6,
0x6e, 0x9a, 0x27, 0xd9,
0x21, 0x0f, 0x1f, 0x7d,
0xe2, 0xee, 0x7a, 0xeb,
0xd9, 0x04, 0x65, 0xb1,
0xa5, 0xa4, 0xcc, 0xe1,
0x9d, 0xca, 0x51, 0x3a,
0xe8, 0x5f, 0x9c, 0x4d,
0x6a, 0xb7, 0x4d, 0xc4,
0xff, 0xa0, 0x27, 0xf8,
0x3f, 0xac, 0xe3, 0x25,
0x4b, 0xfd, 0x1b, 0x69,
0xb1, 0x50, 0x18, 0xbb,
0x58, 0x94, 0x1a, 0x8c,
0xf4, 0xa4, 0xe5, 0x59,
0x06, 0x57, 0x51, 0x36,
0x37, 0xf6, 0x1e, 0x45,
0x01, 0x32, 0xdb, 0x5e,
0xa7, 0x9d, 0x91, 0xee,
0xaf, 0x65, 0x63, 0x3c,
0x58, 0xa9, 0xb8, 0x94,
0x45, 0x9d, 0x7a, 0x24,
0x46, 0x00, 0xa0, 0x0a,
0x5b, 0x42, 0x4d, 0xa2,
0xf1, 0xf6, 0x40, 0xe4,
0x12, 0xcd, 0x9c, 0x03,
0xe0, 0x54, 0xd7, 0x69,
0xed, 0xd1, 0x10, 0x85,
0x9c, 0xb5, 0x58, 0x40,
0xef, 0x41, 0xcb, 0x18,
0xe1, 0xa3, 0x99, 0x0e,
0xa7, 0x75, 0x5f, 0x27,
0xbe, 0xf9, 0xa0, 0x4a,
0x38, 0xbc, 0x29, 0x65,
0x2d, 0xa7, 0x9d, 0xd1,
0x35, 0xb1, 0x48, 0x46,
0xef, 0x8c, 0x22, 0x4d,
0xbb, 0x77, 0xd2, 0x42,
0xe4, 0x8b, 0xf1, 0xb7,
0x2c, 0xf2, 0xab, 0xd6,
0xce, 0x0b, 0x32, 0x61,
0x23, 0x4d, 0xd1, 0xc2,
0x9d, 0x84, 0xf0, 0xe9,
0x2d, 0xb0, 0x3f, 0x9a,
0xd1, 0x52, 0xdf, 0xc8,
0xcd, 0xbd, 0x97, 0x0c,
0x32, 0x86, 0x82, 0xb1,
0x16, 0x0d, 0x88, 0x62,
0xd3, 0x78, 0x88, 0xd3,
0xb5, 0x65, 0x2f, 0x08,
0xa7, 0x40, 0x32, 0x97,
0xd3, 0x24, 0xa7, 0xbf,
0x4d, 0x0b, 0x7a, 0xf9,
0x8a, 0x94, 0xb0, 0xf1,
0x47, 0xbf, 0xbe, 0xce,
0x06, 0xf3, 0x83, 0x00,
0xf7, 0x0b, 0x2f, 0x27,
0xe5, 0xe3, 0x3c, 0x11,
0xa9, 0xfe, 0x95, 0x96,
0xbc, 0x60, 0x8c, 0xcc,
0x21, 0x87, 0x69, 0x80,
0x81, 0x10, 0xb7, 0x3d,
0xad, 0x7b, 0xa4, 0x6b,
0xd9, 0xf1, 0x32, 0x2a,
0xc5, 0x15, 0x1f, 0xc7,
0x9b, 0x58, 0x50, 0xf7,
0x00, 0x00, 0x00, 0xbd,
0x00, 0x00, 0x00, 0x04,
0x5f, 0x00, 0x00, 0x00,
0x75, 0x50, 0xd6, 0x95,
0x80, 0x80, 0x00, 0x00









/*  This is an example of how the pasted dump should look like:

    0x04, 0x4C, 0x4F, 0x8F,
    0x2A, 0xE3, 0x3E, 0x81,
    0x76, 0x48, 0x0F, 0xE0,
    0xF1, 0x10, 0xFF, 0xEE,
    ...
    0x01, 0x00, 0x0F, 0xBD,
    0x00, 0x00, 0x00, 0x04,
    0x5F, 0x00, 0x00, 0x00,
    0xCC, 0xF9, 0xBE, 0x37,
    0x80, 0x80, 0x00, 0x00   <-- Notice the absence of the coma in the end of the last line.

*/
  };


  // Write main data
  for (byte page = 3; page < pages; page++) {
    // Write data to the page
    Serial.print(F("Writing data into page ")); Serial.print(page);
    Serial.println(F(" ..."));
    dump_byte_array(dataBlock + (page * 4), 4); Serial.println();
    nfc.mifareclassic_WriteDataBlock(page, dataBlock + (page * 4));
//    if (status != MFRC522::STATUS_OK) {
//      Serial.print(F("MIFARE_Write() failed: "));
//      Serial.println(mfrc522.GetStatusCodeName(status));
//      Serial.println("Write process failed, please try once more.");
//      Serial.println("Your tag is still fine, just remove it and put back again in 3 seconds.");
//      delay(1000);
//      Serial.println();
//      Serial.print("New attempt in 3...");
//      delay(1000);
//      Serial.print("2...");
//      delay(1000);
//      Serial.print("1...");
//      delay(1000);
//      Serial.println();
//      Serial.println();
//      Serial.println("Ready to write.");
//      return;
//    }
    Serial.println();
  }

  // Write lock bytes - the last thing you should do.
  // If you write them too early - your tag is wasted.
  // Write the Dynamic Lock Bytes
  byte DynamicLockBlock[]    = {
    0x01, 0x00, 0x0F, 0xBD
  };
  Serial.print(F("Writing Dynamic Lock Bytes into page 130"));
  Serial.println(F(" ..."));
  dump_byte_array(DynamicLockBlock, 4); Serial.println();
  nfc.mifareclassic_WriteDataBlock(130, DynamicLockBlock);
//  if (status != MFRC522::STATUS_OK) {
//    Serial.print(F("MIFARE_Write() failed: "));
//    Serial.println(mfrc522.GetStatusCodeName(status));
//  }
  Serial.println();

  // Now we can write Static Lock Bytes
  byte StaticLockBlock[]    = {
    0x0F, 0xE0, 0x0F, 0xE0
  };
  Serial.print(F("Writing Static Lock Bytes into page 2"));
  Serial.println(F(" ..."));
  dump_byte_array(StaticLockBlock, 4); Serial.println();
  nfc.mifareclassic_WriteDataBlock(2, StaticLockBlock);
//  if (status != MFRC522::STATUS_OK) {
//    Serial.print(F("MIFARE_Write() failed: "));
//    Serial.println(mfrc522.GetStatusCodeName(status));
//  }
  Serial.println();

  // Halt PICC
//  mfrc522.PICC_HaltA();
//  // Stop encryption on PCD
//  mfrc522.PCD_StopCrypto1();

  Serial.println("Write process finished! Now please take your Amiibo card away!");
  delay(30000);
}

/**
   Helper routine to dump a byte array as hex values to Serial.
*/
void dump_byte_array(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
}
