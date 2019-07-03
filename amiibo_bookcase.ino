#include <WaveHC.h>
#include <WaveUtil.h>
#include <Wire.h>
#include <Adafruit_NFCShield_I2C.h>
//#include <MemoryFree.h>

//Loading Strings into PROGMEM to save RAM
#include <avr/pgmspace.h>
//Character Intro File Names
const char intro_0[] PROGMEM = "cfalc.wav";
const char intro_1[] PROGMEM = "samus.wav";
const char intro_2[] PROGMEM = "lmac.wav";
const char intro_3[] PROGMEM = "fox.wav";
const char intro_4[] PROGMEM = "wft.wav";
const char intro_5[] PROGMEM = "villager.wav";
const char intro_6[] PROGMEM = "marth.wav";
const char intro_7[] PROGMEM = "yoshi.wav";
const char intro_8[] PROGMEM = "pit.wav";
const char intro_9[] PROGMEM = "kirby.wav";
const char intro_10[] PROGMEM = "pikachu.wav";
const char intro_11[] PROGMEM = "link.wav";
const char intro_12[] PROGMEM = "luigi.wav";
const char intro_13[] PROGMEM = "luigi2.wav";
const char intro_14[] PROGMEM = "diddy.wav";
const char intro_15[] PROGMEM = "dk.wav";
const char intro_16[] PROGMEM = "peach.wav";
const char intro_17[] PROGMEM = "zelda.wav";
const char intro_18[] PROGMEM = "mario.wav";
const char intro_19[] PROGMEM = "tlink.wav";
const char intro_20[] PROGMEM = "dede.wav";
const char intro_21[] PROGMEM = "lucario.wav";
const char intro_22[] PROGMEM = "bowser.wav";
const char intro_23[] PROGMEM = "mega.wav";
const char intro_24[] PROGMEM = "sonic.wav";
const char intro_25[] PROGMEM = "rosa.wav";
const char intro_26[] PROGMEM = "mk.wav";
const char intro_27[] PROGMEM = "shulk.wav";
const char intro_28[] PROGMEM = "sheik.wav";
const char intro_29[] PROGMEM = "ike.wav";
  //Wave 4 - Intros
const char intro_30[] PROGMEM = "robin.wav";
const char intro_31[] PROGMEM = "lucina.wav";
const char intro_32[] PROGMEM = "char.wav";
const char intro_33[] PROGMEM = "wario.wav";
const char intro_34[] PROGMEM = "pacman.wav";
const char intro_35[] PROGMEM = "ness.wav";
const char intro_36[] PROGMEM = "ganon.wav";
const char intro_37[] PROGMEM = "gren.wav";
const char intro_38[] PROGMEM = "jiggly.wav";
  //Wave 5+ - Intros
const char intro_39[] PROGMEM = "dpit.wav";
const char intro_40[] PROGMEM = "palu.wav";
const char intro_41[] PROGMEM = "zss.wav";
const char intro_42[] PROGMEM = "dmario.wav";
const char intro_43[] PROGMEM = "bowjr.wav";
const char intro_44[] PROGMEM = "olimar.wav";
const char intro_45[] PROGMEM = "mrgw.wav";
const char intro_46[] PROGMEM = "rob.wav";
const char intro_47[] PROGMEM = "duck.wav";
const char intro_48[] PROGMEM = "miib.wav";
const char intro_49[] PROGMEM = "miis.wav";
const char intro_50[] PROGMEM = "miig.wav";
const char intro_51[] PROGMEM = "mewtwo.wav";
const char intro_52[] PROGMEM = "falco.wav";
const char intro_53[] PROGMEM = "lucas.wav";
const char intro_54[] PROGMEM = "shovelk.wav";
const char intro_55[] PROGMEM = "roy.wav";
const char intro_56[] PROGMEM = "ryu.wav";
const char intro_57[] PROGMEM = "cloud.wav";
const char intro_58[] PROGMEM = "corrin.wav";
const char intro_59[] PROGMEM = "bayo.wav";
  //Non-Smash Intros
const char intro_60[] PROGMEM = "inkg.wav";
const char intro_61[] PROGMEM = "inkb.wav";
const char intro_62[] PROGMEM = "squid.wav";
const char intro_63[] PROGMEM = "chibi.wav";
const char intro_64[] PROGMEM = "yarn.wav";
const char intro_65[] PROGMEM = "wlink.wav";
const char intro_66[] PROGMEM = "eggman.wav";
const char intro_67[] PROGMEM = "guard.wav";
const char intro_68[] PROGMEM = "bokob.wav";
const char intro_69[] PROGMEM = "toad.wav";
const char intro_70[] PROGMEM = "gyoshi.wav";
const char intro_71[] PROGMEM = "pyoshi.wav";
const char intro_72[] PROGMEM = "byoshi.wav";
const char intro_73[] PROGMEM = "myoshi.wav";
const char intro_74[] PROGMEM = "smario.wav";
const char intro_75[] PROGMEM = "gmario.wav";
const char intro_76[] PROGMEM = "tzelda.wav";
const char intro_77[] PROGMEM = "alink.wav";
const char intro_78[] PROGMEM = "rlink.wav";
const char intro_79[] PROGMEM = "boo.wav";
const char intro_80[] PROGMEM = "daisy.wav";
const char intro_81[] PROGMEM = "wal.wav";
const char intro_82[] PROGMEM = "gmega.wav";
const char intro_83[] PROGMEM = "waddle.wav";
const char intro_84[] PROGMEM = "alm.wav";
const char intro_85[] PROGMEM = "celica.wav";
const char intro_86[] PROGMEM = "callie.wav";
const char intro_87[] PROGMEM = "marie.wav";
const char intro_88[] PROGMEM = "cloud2.wav";
const char intro_89[] PROGMEM = "bayo2.wav";
const char intro_90[] PROGMEM = "corrin2.wav";
const char intro_91[] PROGMEM = "pikmin.wav";
const char intro_92[] PROGMEM = "kopat.wav";
const char intro_93[] PROGMEM = "goomba.wav";
const char intro_94[] PROGMEM = "metro.wav";
const char intro_95[] PROGMEM = "tiki.wav";
const char intro_96[] PROGMEM = "chrom.wav";
const char intro_97[] PROGMEM = "daruk.wav";
const char intro_98[] PROGMEM = "mipha.wav";
const char intro_99[] PROGMEM = "revali.wav";
const char intro_100[] PROGMEM = "urbosa.wav";
const char intro_101[] PROGMEM = "detpik.wav";
const char intro_102[] PROGMEM = "dsouls.wav";
const char intro_103[] PROGMEM = "wolf.wav";
const char intro_104[] PROGMEM = "ridl.wav";

//Songs
const char song_0[] PROGMEM = "cfalc_s.wav";
const char song_1[] PROGMEM = "samus_s.wav";
const char song_2[] PROGMEM = "lmac_s.wav";
const char song_3[] PROGMEM = "fox_s.wav";
const char song_4[] PROGMEM = "wft_s.wav";
const char song_5[] PROGMEM = "vil_s.wav";
const char song_6[] PROGMEM = "marth_s.wav";
const char song_7[] PROGMEM = "yoshi_s.wav";
const char song_8[] PROGMEM = "pit_s.wav";
const char song_9[] PROGMEM = "kirby_s.wav";
const char song_10[] PROGMEM = "pika_s.wav";
const char song_11[] PROGMEM = "link_s.wav";
const char song_12[] PROGMEM = "luigi_s.wav";
const char song_13[] PROGMEM = "luigi2_s.wav";
const char song_14[] PROGMEM = "diddy_s.wav";
const char song_15[] PROGMEM = "dk_s.wav";
const char song_16[] PROGMEM = "peach_s.wav";
const char song_17[] PROGMEM = "zelda_s.wav";
const char song_18[] PROGMEM = "mario_s.wav";
const char song_19[] PROGMEM = "tlink_s.wav";
const char song_20[] PROGMEM = "dede_s.wav";
const char song_21[] PROGMEM = "luca_s.wav";
const char song_22[] PROGMEM = "bowser_s.wav";
const char song_23[] PROGMEM = "mega_s.wav";
const char song_24[] PROGMEM = "sonic_s.wav";
const char song_25[] PROGMEM = "rosa_s.wav";
const char song_26[] PROGMEM = "mk_s.wav";
const char song_27[] PROGMEM = "shulk_s.wav";
const char song_28[] PROGMEM = "sheik_s.wav";
const char song_29[] PROGMEM = "ike_s.wav";
  //Wave 4
const char song_30[] PROGMEM = "robin_s.wav";
const char song_31[] PROGMEM = "lucina_s.wav";
const char song_32[] PROGMEM = "char_s.wav";
const char song_33[] PROGMEM = "wario_s.wav";
const char song_34[] PROGMEM = "pac_s.wav";
const char song_35[] PROGMEM = "ness_s.wav";
const char song_36[] PROGMEM = "ganon_s.wav";
const char song_37[] PROGMEM = "gren_s.wav";
const char song_38[] PROGMEM = "jiggly_s.wav";
  //Wave 5+
const char song_39[] PROGMEM = "dpit_s.wav";
const char song_40[] PROGMEM = "palu_s.wav";
const char song_41[] PROGMEM = "zss_s.wav";
const char song_42[] PROGMEM = "dmaro_s.wav";
const char song_43[] PROGMEM = "bowjr_s.wav";
const char song_44[] PROGMEM = "olimar_s.wav";
const char song_45[] PROGMEM = "mrgw_s.wav";
const char song_46[] PROGMEM = "rob_s.wav";
const char song_47[] PROGMEM = "duck_s.wav";
const char song_48[] PROGMEM = "miib_s.wav";
const char song_49[] PROGMEM = "miis_s.wav";
const char song_50[] PROGMEM = "miig_s.wav";
const char song_51[] PROGMEM = "mewtwo_s.wav";
const char song_52[] PROGMEM = "falco_s.wav";
const char song_53[] PROGMEM = "lucas_s.wav";
const char song_54[] PROGMEM = "shovel_s.wav";
const char song_55[] PROGMEM = "roy_s.wav";
const char song_56[] PROGMEM = "ryu_s.wav";
const char song_57[] PROGMEM = "cloud_s.wav";
const char song_58[] PROGMEM = "corrin_s.wav";
const char song_59[] PROGMEM = "bayo_s.wav";
  //Non-Smash
const char song_60[] PROGMEM = "inkg_s.wav";
const char song_61[] PROGMEM = "inkb_s.wav";
const char song_62[] PROGMEM = "squid_s.wav";
const char song_63[] PROGMEM = "chibi_s.wav";
const char song_64[] PROGMEM = "yarn_s.wav";
const char song_65[] PROGMEM = "wlink_s.wav";
const char song_66[] PROGMEM = "wlink_sa.wav";
const char song_67[] PROGMEM = "eggman_s.wav";
const char song_68[] PROGMEM = "guard_s.wav";
const char song_69[] PROGMEM = "bokob_s.wav";
const char song_70[] PROGMEM = "toad_s.wav";
const char song_71[] PROGMEM = "wwtzelda.wav";
const char song_72[] PROGMEM = "botw.wav";
const char song_73[] PROGMEM = "boo_s.wav";
const char song_74[] PROGMEM = "daisy_s.wav";
const char song_75[] PROGMEM = "wal_s.wav";
const char song_76[] PROGMEM = "waddle_s.wav";
const char song_77[] PROGMEM = "alm_s.wav";
const char song_78[] PROGMEM = "celica_s.wav";
const char song_79[] PROGMEM = "callie_s.wav";
const char song_80[] PROGMEM = "marie_s.wav";
const char song_81[] PROGMEM = "cloud2_s.wav";
const char song_82[] PROGMEM = "bayo2_s.wav";
const char song_83[] PROGMEM = "kopat_s.wav";
const char song_84[] PROGMEM = "goomba_s.wav";
const char song_85[] PROGMEM = "metro_s.wav";
const char song_86[] PROGMEM = "tiki_s.wav";
const char song_87[] PROGMEM = "chrom_s.wav";
const char song_88[] PROGMEM = "daruk_s.wav";
const char song_89[] PROGMEM = "mipha_s.wav";
const char song_90[] PROGMEM = "revali_s.wav";
const char song_91[] PROGMEM = "urbosa_s.wav";
const char song_92[] PROGMEM = "wed_s.wav";
const char song_93[] PROGMEM = "detpik_s.wav";
const char song_94[] PROGMEM = "kirby2_s.wav";
const char song_95[] PROGMEM = "dsouls_s.wav";
const char song_96[] PROGMEM = "wolf_s.wav";
const char song_97[] PROGMEM = "ridl_s.wav";

// Then set up a table to refer to your strings.

const char* const intro_table[] PROGMEM = 
{
  intro_0,
  intro_1,
  intro_2,
  intro_3,
  intro_4,
  intro_5,
  intro_6,
  intro_7,
  intro_8,
  intro_9,
  intro_10,
  intro_11,
  intro_12,
  intro_13,
  intro_14,
  intro_15,
  intro_16,
  intro_17,
  intro_18,
  intro_19,  
  intro_20,  
  intro_21,  
  intro_22,  
  intro_23,  
  intro_24,  
  intro_25,  
  intro_26,  
  intro_27,  
  intro_28,  
  intro_29,  
  intro_30,
  intro_31,
  intro_32,
  intro_33,
  intro_34,
  intro_35,
  intro_36,
  intro_37,
  intro_38,
  intro_39,
  intro_40,
  intro_41,
  intro_42,
  intro_43,
  intro_44,
  intro_45,
  intro_46,
  intro_47,
  intro_48,
  intro_49,
  intro_50,
  intro_51,
  intro_52,
  intro_53,
  intro_54,
  intro_55,
  intro_56,
  intro_57,
  intro_58,
  intro_59,
  intro_60,
  intro_61,
  intro_62,
  intro_63,
  intro_64,
  intro_65,
  intro_66,
  intro_67,
  intro_68,
  intro_69,
  intro_70,
  intro_71,
  intro_72,
  intro_73,
  intro_74,
  intro_75,
  intro_76,
  intro_77,
  intro_78,
  intro_79,
  intro_80,
  intro_81,
  intro_82,
  intro_83,
  intro_84,
  intro_85,
  intro_86,
  intro_87,
  intro_88,
  intro_89,
  intro_90,
  intro_91,
  intro_92,
  intro_93,
  intro_94,
  intro_95,
  intro_96,
  intro_97,
  intro_98,
  intro_99,
  intro_100,
  intro_101,
  intro_102,
  intro_103,
  intro_104,
};

const char* const song_table[] PROGMEM =      
{
  song_0,
  song_1,
  song_2,
  song_3,
  song_4,
  song_5,
  song_6,
  song_7,
  song_8,
  song_9,
  song_10,
  song_11,
  song_12,
  song_13,
  song_14,
  song_15,
  song_16,
  song_17,
  song_18,
  song_19,  
  song_20,  
  song_21,  
  song_22,  
  song_23,  
  song_24,  
  song_25,  
  song_26,  
  song_27,  
  song_28,  
  song_29,  
  song_30,
  song_31,
  song_32,
  song_33,
  song_34,
  song_35,
  song_36,
  song_37,
  song_38,
  song_39,
  song_40,
  song_41,
  song_42,
  song_43,
  song_44,
  song_45,
  song_46,
  song_47,
  song_48,
  song_49,
  song_50,
  song_51,
  song_52,
  song_53,
  song_54,
  song_55,
  song_56,
  song_57,
  song_58,
  song_59,
  song_60,
  song_61,
  song_62,
  song_63,
  song_64,
  song_65,
  song_66,
  song_67,
  song_68,
  song_69,
  song_70,
  song_71,
  song_72,
  song_73,
  song_74,
  song_75,
  song_76,
  song_77,
  song_78,
  song_79,
  song_80,
  song_81,
  song_82,
  song_83,
  song_84,
  song_85,
  song_86,
  song_87,
  song_88,
  song_89,
  song_90,
  song_91,
  song_92,
  song_93,
  song_94,
  song_95,
  song_96,
  song_97,
};

char buffer[30];

#define IRQ 6 // this trace must be cut and rewired!
#define RESET 8

Adafruit_NFCShield_I2C nfc(IRQ, RESET);

SdReader card; // This object holds the information for the card
FatVolume vol; // This holds the information for the partition on the card
FatReader root; // This holds the information for the volumes root directory
FatReader file; // This object represent the WAV file for a pi digit or period
WaveHC wave; // This is the only wave (audio) object, since we will only play one at a time
/*
* Define macro to put error messages in flash memory
*/
#define error(msg) error_P(PSTR(msg))

//Setup()
uint32_t versiondata;

//My Added Variables
uint32_t lastcard = 0;
uint32_t currentcard = 1;
//uint32_t CID = 0;
uint32_t CID22 = 0;
boolean songplaying = false;

//Loop()
uint32_t cardidentifier = 0;
uint8_t success;
uint8_t page22;
uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 }; // Buffer to store the returned UID
uint8_t uidLength; // Length of the UID (4 or 7 bytes depending on ISO14443A card type)
bool wlinkAlternate = false;
//unsigned long currentMillis;
//unsigned long oldMillis = 0;
 
//////////////////////////////////// SETUP

void setup() {
  // set up Serial library at 115200 bps
  Serial.begin(115200);
  
  PgmPrintln("Amiibo Scanner");
  
  if (!card.init()) {
    error("Card init. failed!");
  }
  if (!vol.init(card)) {
    error("No partition!");
  }
  if (!root.openRoot(vol)) {
    error("Couldn't open dir");
  }
  
  PgmPrintln("Files found:");
  root.ls();
  
  // find Adafruit RFID/NFC shield
  nfc.begin();

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

}

/////////////////////////////////// LOOP

unsigned digit = 0;

void loop() 
{
  
  //Memory Checker
  
  //Serial.print(F("Memory Available = "));
  //Serial.println(freeMemory());
  
  // wait for RFID card to show up!
  Serial.println(F("Waiting for an Amiibo ..."));

    
  // Wait for an ISO14443A type cards (Mifare, etc.). When one is found
  // 'uid' will be populated with the UID, and uidLength will indicate
  // if the uid is 4 bytes (Mifare Classic) or 7 bytes (Mifare Ultralight)
  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength);

  cardidentifier = 0;
  CID22 = 999; 
  if (success) 
  {
    // Found a card!
    Serial.print(uid[0]);
    Serial.print(uid[1]);
    Serial.print(uid[2]);
    Serial.print(uid[3]);
    Serial.print(uid[4]);
    Serial.print(uid[5]);
    Serial.print(uid[6]);
    Serial.print(uid[7]);
    Serial.print(F("Amiibo detected #"));
    // turn the four byte UID of a mifare classic into a single variable #
    cardidentifier = uid[3];
    cardidentifier <<= 8; cardidentifier |= uid[2];
    cardidentifier <<= 8; cardidentifier |= uid[1];
    cardidentifier <<= 8; cardidentifier |= uid[0];
    Serial.println(cardidentifier);
    
    //Check the previous card
    
    (lastcard = currentcard);
    (currentcard = cardidentifier);
    
    Serial.print(F("Last Amiibo:    #"));
    Serial.println(lastcard);
    Serial.print(F("Current Card:"));
    Serial.println(currentcard);
    
    // Check Character ID
    
      // Try to read the Character info page (#21)
//      uint8_t charID[32];
      uint8_t charTest[32];
//      success = nfc.mifareultralight_ReadPage (21, charID);
      success = nfc.mifareultralight_ReadPage (22, charTest);
      if(currentcard == 2870272106)
      {
        success = true;
      }
    if (success)
    {
//      if (oldMillis != 0){
//        oldMillis = millis();
//      }
        // turn page 21 into a character ID
      if(currentcard != 2870272106)
      {        
         // looks like 0, 1, on page 22 is all thats needed if you want unique amiibo
         // page 21
         // WWXXYYZZ
         // WW - Seems to signify the series/franchise the character is from. Smaller series/franchises are grouped together with other ones to save space for other potential franchises.
         // XX - The character's number in that series. For series that are grouped together, the starting number for that series is separated by a fair amount, likely for organizational purposes.
         // YY - Represents distinct versions of the same character as well as the one-offs for Retro/Dead franchises that won't have more than one character. Example: Link/Toon Link, Zelda/Sheik, Samus/Zero Suit, Miis, G&W/ROB/Duck Hunt, and the Inkling Squid/Boy/Girl.
         // ZZ - 00-Figures, 01-Cards, 02-Yarn 
         
         // page 22
         // XXXXYYZZ
         // XXXX - The Amiibo's unique number. It start's with Mario at 0000 and goes up by one with every different Amiibo. There's 65536 possible slots so there is little chance of Nintendo running out. Special edition Amiibos like Gold/Silver Mario use a unique ID for each figure rather than share the ID with their regular edition counterparts.
         // YY - The Amiibo's series.
           // 00 - Smash Series
           // 01 - Mario Series
           // 02 - Chibi Robo
           // 03 - Wooly World
           // 04 - Splatoon Series
           // 05 - Animal Crossing
           // 06 - 8-bit Mario
           // 07 - Skylanders
           // 08 - 
           // 09 - Legend of Zelda
           // 0A - Shovel Knight
           // 0B - 
           // 0C - Kirby
           // 0D - Pokken Tournament
           // 0E - Mario Sport Superstars
           // 0F - Monster Hunter
         // ZZ - Also unknown. It's always been 02 so far.  
           
        CID22 = charTest[0];        
        CID22 <<= 8;
        CID22 = CID22 + charTest[1]; // This will give the unique code for each Amiibo      
          
//        CID = charID[6];
//        CID <<= 8; CID |= charID[6];
//        CID <<= 8; CID |= charID[5];
//        CID <<= 8; CID |= charID[4];
//        CID <<= 8; CID |= charID[3];
//        CID <<= 8; CID |= charID[2];
//        CID <<= 8; CID |= charID[1];
//        CID <<= 8; CID |= charID[0];
        Serial.print("Character Number: ");
//        Serial.println(CID);
        Serial.println(CID22);
        Serial.print("Series ID: ");
        // this line is for the series, convert from dec to hex to get seriesID
        Serial.println(charTest[2]);
      }
      else
      {
        CID22 = 2870272106;
      }
    
    
      if (currentcard == lastcard) 
      {
      /*
        If there is no song playing, play a song.
      */
        if (songplaying == false) 
        {
          //Captain Falcon Song
          if (CID22 == 18) 
          //if (CID == 6)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[0])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Samus Song
          if (CID22 == 6 || CID22 == 869)
          //if (CID == 49157)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[1])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Little Mac Song
          if (CID22 == 15) 
          //if (CID == 49158)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[2])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Fox Song
          if (CID22 == 5) 
          //if (CID == 32773)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[3])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
         //Wii Fit Song 
          if (CID22 == 7) 
          //if (CID == 7)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[4])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Villager Song        
          if (CID22 == 8)
          //if (CID == 32769)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[5])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Marth Song
          if (CID22 == 11)
          //if (CID == 33)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[6])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Yoshi Song
          if (CID22 == 2 || CID22 == 55)
          //if (CID == 768)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[7])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Pit Song
          if (CID22 == 16)
          //if (CID == 16391)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[8])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Kirby Song
          if (CID22 == 10)
          //if (CID == 31)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[9])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Pikachu Song
          if (CID22 == 9)
          //if (CID == 6425)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[10])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Link Song
          if (CID22 == 4 || CID22 == 843 || CID22 == 847 || CID22 == 844 || CID22 == 846)
          //if (CID == 1)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[11])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Luigi Song
          if (CID22 == 12 || CID22 == 53)
          //if (CID == 256)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[12])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Diddy Song
          if (CID22 == 13 || CID22 == 613)
          //if (CID == 2304)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[14])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //DK Song
          if (CID22 == 3 || CID22 == 612 || CID22 == 571)
          //if (CID == 2048)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[15])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Peach Song
          if (CID22 == 1 || CID22 == 54 || CID22 == 882)
          //if (CID == 512)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[16])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Zelda Song
          if (CID22 == 14)
          //if (CID == 257)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[17])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Mario Song
          if (CID22 == 0 || CID22 == 52 || CID22 == 60 || CID22 == 61 || CID22 == 568 || CID22 == 569)
          //if (CID == 0)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[18])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Toonlink Song
          if (CID22 == 22 || CID22 == 848)
          //if (CID == 65537)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[19])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Dedede Song
          if (CID22 == 40 || CID22 == 598)
          //if (CID == 543)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[20])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Lucario Song
          if (CID22 == 17)
          //if (CID == 49178)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[21])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Bowser Song
          if (CID22 == 20 || CID22 == 57 || CID22 == 570 || CID22 == 883)
          //if (CID == 1280)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[22])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Mega Man Song
          if (CID22 == 49 || CID22 == 600)
          //if (CID == 32820)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[23])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Sonic Song
          if (CID22 == 48)
          //if (CID == 50)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[24])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Rosalina Song
          if (CID22 == 19 || CID22 == 610)
          //if (CID == 66560)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[25])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //MetaKnight Song
          if (CID22 == 39 || CID22 == 597)
          //if (CID == 287)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[26])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Shulk Song
          if (CID22 == 43)
          //if (CID == 16418)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[27])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Sheik Song
          if (CID22 == 23)
          //if (CID == 65793)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[28])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Ike Song
          if (CID22 == 24)
          //if (CID == 289)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[29])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Robin Song
          if(CID22 == 42)
          //if (CID == 801)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[30])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Lucina Song
          if (CID22 == 41)
          //if (CID == 545)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[31])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Charizard Song
          if (CID22 == 36)
          //if (CID == 1561)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[32])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Wario Song
          if (CID22 == 26 || CID22 == 611)
          //if (CID == 1792)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[33])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Pac-Man Song
          if (CID22 == 50)
          //if (CID == 16435)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[34])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Ness Song
          if (CID22 == 44)
          //if (CID == 32802)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[35])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Gannondorf Song
          if (CID22 == 27)
          //if (CID == 66049)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[36])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Greninja Song
          if (CID22 == 37)
          //if (CID == 37403)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[37])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Jigglypuff Song
          if (CID22 == 38)
          //if (CID == 10009)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[38])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Dark Pit Song
          if (CID22 == 32)
          //if (CID == 16647)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[39])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Palutena Song
          if (CID22 == 31)
          //if (CID == 16903)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[40])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Zero Suit Song
          if (CID22 == 29)
          //if (CID == 114693)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[41])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Dr Mario Song
          if (CID22 == 25)
          //if (CID == 65536)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[42])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Bowser Jr Song
          if (CID22 == 21)
          //if (CID == 1536)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[43])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Olimar Song
          if (CID22 == 30 || CID22 == 863)
          //if (CID == 81926)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[44])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Mr Game & Watch Song
          if (CID22 == 45)
          //if (CID == 32775)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[45])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Rob Song
          if (CID22 == 46 || CID22 == 51)
          //if (CID == 33031)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[46])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Duck Hunt Song
          if (CID22 == 47)
          //if (CID == 33287)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[47])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Mii Brawler Song
          if (CID22 == 33)
          //if (CID == 49159)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[48])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Mii Swordfighter Song
          if (CID22 == 34)
          //if (CID == 114695)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[49])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Mii Gunner Song
          if (CID22 == 35)
          //if (CID == 180231)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[50])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Mewtwo Song
          if (CID22 == 573)
          //if (CID == 38425)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[51])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Falco Song
          if (CID22 == 28)
          //if (CID == 33029)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[52])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Lucas Song
          if (CID22 == 593)
          //if (CID == 33058)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[53])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Shovel Knight Song
          if (CID22 == 592)
          //if (CID == 49205)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[54])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Roy Song
          if (CID22 == 594)
          //if (CID == 1057)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[55])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Ryu Song
          if (CID22 == 595)
          //if (CID == 49204)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[56])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Cloud Song
          if (CID22 == 601)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[57])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Corrin Song
          if (CID22 == 602 || CID22 == 867)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[58])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Bayonetta Song
          if (CID22 == 603)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[59])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
        //Non-Smash
          //Inkling Girl Song
          if (CID22 == 62 || CID22 == 607 || CID22 == 873 || CID22 == 898)
          //if (CID == 65544)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[60])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Inkling Boy Song
          if (CID22 == 63 || CID22 == 608 || CID22 == 874)
          //if (CID == 131080)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[61])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Squid Song
          if (CID22 == 64 || CID22 == 609 || CID22 == 875)
          //if (CID == 196616)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[62])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Chibi Robo Song
          if (CID22 == 49186)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[63])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Yarn Yoshi Song
          if (CID22 == 65 || CID22 == 66 || CID22 == 67 || CID22 == 574)
          //if (CID == 33620736)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[64])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }          
          //Wolf Link Song + Link, twilight princess
          if (CID22 == 591 || CID22 == 845)
          //if (CID == 769)      
          {
            if(wlinkAlternate == false){strcpy_P(buffer, (char*)pgm_read_word(&(song_table[65]))); wlinkAlternate = true;}
            else{strcpy_P(buffer, (char*)pgm_read_word(&(song_table[66]))); wlinkAlternate = false;}
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Robotnik Song
          if (CID22 == 2870272106 || CID22 == 65535)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[67])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Guardian Song
          if (CID22 == 853)
          //if (CID == 16385)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[68])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Bokoblin Song
          if (CID22 == 860)
          //if (CID == 16641)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[69])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //Toad Song
          if (CID22 == 56)
          //if (CID == 2560)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[70])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          //WW Toon Zelda Song
          if (CID22 == 850)
          //if (CID == 257)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[71])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }          
          //BOTW Toon Zelda - Link A/R Song
          if (CID22 == 854 || CID22 == 851 || CID22 == 852)
          //if (CID == 257)      
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[72])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }          
          //BOO Song
          if (CID22 == 616)
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[73])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }       
          //Daisy Song
          if (CID22 == 614)
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[74])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }       
          //Waluigi Song
          if (CID22 == 615)
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[75])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }       
          //Waddle Dee Song
          if (CID22 == 599)
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[76])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }       
          //Alm Song
          if (CID22 == 864)
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[77])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }       
          //Celica Song
          if (CID22 == 865)
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[78])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }       
          //Callie Song
          if (CID22 == 605)
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[79])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }       
          //Marie Song
          if (CID22 == 606)
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[80])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }       
          //Cloud2 Song
          if (CID22 == 866)
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[81])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }       
          //Bayonetta2 Song
          if (CID22 == 868)
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[82])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }      
          //Koopa Troopa Song
          if (CID22 == 872)
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[83])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }      
          //Goomba Song
          if (CID22 == 871)
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[84])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }      
          //Metroid Song
          if (CID22 == 870)
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[85])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }      
          //Tiki Song
          if (CID22 == 880)
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[86])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }      
          //Chrom Song
          if (CID22 == 879)
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[87])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }      
          //Daruk Song
          if (CID22 == 856)
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[88])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }      
          //Mipha Song
          if (CID22 == 858)
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[89])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }          
          //Revali Song
          if (CID22 == 859)
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[90])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }    
          //Urbosa Song
          if (CID22 == 857)
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[91])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }    
          //Wedding Mario Song
          if (CID22 == 881)
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[92])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }    
          //Detective Pikachu Song
          if (CID22 == 885)
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[93])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }    
          //Kirby Powerglove Song
          if (CID22 == 596)
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[94])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }    
          //Dark Souls Song
          if (CID22 == 888)
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[95])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }    
          //Wolf Song
          if (CID22 == 894)
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[96])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }    
          //Ridley Song
          if (CID22 == 895)
          {strcpy_P(buffer, (char*)pgm_read_word(&(song_table[97])));
            playfile(buffer);
            if (wave.isplaying) {
              songplaying = true;
            }
          }
          
        }
        
        if(!wave.isplaying) 
        {
          songplaying = false;
        }  
      }
      /*
        There is no song playing, play the intro sequence!
      */
      else 
      {        
        //Captain Falcon
        if (CID22 == 18) 
        //if (CID == 6)  
        {
          strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[0])));
          playcomplete(buffer);
        }
        //Samus
        if (CID22 == 6 || CID22 == 869)
        //if (CID == 49157)  
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[1])));
          playcomplete(buffer);
        }
        //Little Mac
        if (CID22 == 15) 
        //if (CID == 49158)  
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[2])));
          playcomplete(buffer);
        }
        //Fox
        if (CID22 == 5) 
        //if (CID == 32773) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[3])));
          playcomplete(buffer);
        }
        //Wii Fit
        if (CID22 == 7) 
        //if (CID == 7) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[4])));
          playcomplete(buffer);
        }
        //Villager
        if (CID22 == 8)
        //if (CID == 32769) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[5])));
          playcomplete(buffer);
        }
        //Marth
        if (CID22 == 11)
        //if (CID == 33) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[6])));
          playcomplete(buffer);
        }
        //Yoshi
        if (CID22 == 2 || CID22 == 55)
        //if (CID == 768)  
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[7])));
          playcomplete(buffer);
        }
        //Pit
        if (CID22 == 16)
        //if (CID == 16391) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[8])));
          playcomplete(buffer);
        }
        //Kirby
        if (CID22 == 10 || CID22 == 596)
        //if (CID == 31) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[9])));
          playcomplete(buffer);
        }
        //Pikachu
        if (CID22 == 9)
        //if (CID == 6425) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[10])));
          playcomplete(buffer);
        }
        //Link
        if (CID22 == 4 || CID22 == 843 || CID22 == 847 || CID22 == 845 || CID22 == 844 || CID22 == 846)
        //if (CID == 1) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[11])));
          playcomplete(buffer);
        }
        //Luigi
        if (CID22 == 12 || CID22 == 53)
        //if (CID == 256) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[12])));
          playcomplete(buffer);
        }
        //Diddy Kong
        if (CID22 == 13 || CID22 == 613)
        //if (CID == 2304) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[14])));
          playcomplete(buffer);
        }
        //DK
        if (CID22 == 3 || CID22 == 612 || CID22 == 571)
        //if (CID == 2048)  
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[15])));
          playcomplete(buffer);
        }
        //Peach
        if (CID22 == 1 || CID22 == 54 || CID22 == 882)
        //if (CID == 512) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[16])));
          playcomplete(buffer);
        }
        //Zelda
        if (CID22 == 14 || CID22 == 854)
        //if (CID == 257)
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[17])));
          playcomplete(buffer);
        }
        //Mario
        if (CID22 == 0 || CID22 == 52 || CID22 == 568 || CID22 == 569 || CID22 == 881)
        //if (CID == 0)   
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[18])));
          playcomplete(buffer);
        }
        //Toon Link
        if (CID22 == 22 || CID22 == 848)
        //if (CID == 65537) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[19])));
          playcomplete(buffer);
        }
        //Dedede
        if (CID22 == 40 || CID22 == 598)
        //if (CID == 543)
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[20])));
          playcomplete(buffer);
        }
        //Lucario
        if (CID22 == 17)
        //if (CID == 49178) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[21])));
          playcomplete(buffer);
        }
        //Bowser
        if (CID22 == 20 || CID22 == 57 || CID22 == 570 || CID22 == 883)
        //if (CID == 1280) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[22])));
          playcomplete(buffer);
        }
        //Mega Man
        if (CID22 == 49)
        //if (CID == 32820)
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[23])));
          playcomplete(buffer);
        }
        //Sonic
        if (CID22 == 48)
        //if (CID == 50) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[24])));
          playcomplete(buffer);
        }
        //Rosalina
        if (CID22 == 19 || CID22 == 610)
        //if (CID == 66560)
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[25])));
          playcomplete(buffer);
        }
        //Meta Knight
        if (CID22 == 39 || CID22 == 597)
        //if (cID == 287) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[26])));
          playcomplete(buffer);
        }
        //Shulk
        if (CID22 == 43)
        //if (CID == 16418)
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[27])));
          playcomplete(buffer);
        }
        //Sheik
        if (CID22 == 23)
        //if (CID == 65793)
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[28])));
          playcomplete(buffer);
        }
        //Ike
        if (CID22 == 24)
        //if (CID == 289) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[29])));
          playcomplete(buffer);
        }
        //Robin
        if(CID22 == 42)
        //if (CID == 801) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[30])));
          playcomplete(buffer);
        }
        //Lucina
        if (CID22 == 41)
        //if (CID == 545)  
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[31])));
          playcomplete(buffer);
        }
        //Charizard
        if (CID22 == 36)
        //if (CID == 1561) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[32])));
          playcomplete(buffer);
        }
        //Wario
        if (CID22 == 26 || CID22 == 611)
        //if (CID == 1792) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[33])));
          playcomplete(buffer);
        }
        //Pac-Man
        if (CID22 == 50)
        //if (CID == 16435) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[34])));
          playcomplete(buffer);
        }
        //Ness
        if (CID22 == 44)
        //if (CID == 32802) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[35])));
          playcomplete(buffer);
        }
        //Gannondorf
        if (CID22 == 27)
        //if (CID == 66049)
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[36])));
          playcomplete(buffer);
        }
        //Greninja
        if (CID22 == 37)
        //if (CID == 37403) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[37])));
          playcomplete(buffer);
        }
        //Jigglypuff
        if (CID22 == 38)
        //if (CID == 10009) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[38])));
          playcomplete(buffer);
        }
        //Dark Pit
        if (CID22 == 32)
        //if (CID == 16647) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[39])));
          playcomplete(buffer);
        }
        //Palutena
        if (CID22 == 31)
        //if (CID == 16903) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[40])));
          playcomplete(buffer);
        }
        //Zero suit
        if (CID22 == 29)
        //if (CID == 114693) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[41])));
          playcomplete(buffer);
        }
        //Dr Mario
        if (CID22 == 25)
        //if (CID == 65536) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[42])));
          playcomplete(buffer);
        }
        //Bowser Jr
        if (CID22 == 21)
        //if (CID == 1536) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[43])));
          playcomplete(buffer);
        }
        //Olimar
        if (CID22 == 30)
        //if (CID == 81926) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[44])));
          playcomplete(buffer);
        }
        //Mr Game & Watch
        if (CID22 == 45)
        //if (CID == 32775) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[45])));
          playcomplete(buffer);
        }
        //Rob
        if (CID22 == 46 || CID22 == 51)
        //if (CID == 33031) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[46])));
          playcomplete(buffer);
        }
        //Duck Hunt
        if (CID22 == 47)
        //if (CID == 33287) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[47])));
          playcomplete(buffer);
        }
        //Mii Brawler
        if (CID22 == 33)
        //if (CID == 49159) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[48])));
          playcomplete(buffer);
        }
        //Mii Swordfighter
        if (CID22 == 34)
        //if (CID == 114695)  
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[49])));
          playcomplete(buffer);
        }
        //Mii Gunner
        if (CID22 == 35)
        //if (CID == 180231)  
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[50])));
          playcomplete(buffer);
        }
        //Mewtwo
        if (CID22 == 573)
        //if (CID == 38425) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[51])));
          playcomplete(buffer);
        }
        //Falco
        if (CID22 == 28)
        //if (CID == 33029) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[52])));
          playcomplete(buffer);
        }
        //Lucas
        if (CID22 == 593)
        //if (CID == 33058) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[53])));
          playcomplete(buffer);
        }
        //Shovel Knight
        if (CID22 == 592)
        //if (CID == 49205) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[54])));
          playcomplete(buffer);
        }
        //Roy
        if (CID22 == 594)
        //if (CID == 1057) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[55])));
          playcomplete(buffer);
        }
        //Ryu
        if (CID22 == 595)
        //if (CID == 49204) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[56])));
          playcomplete(buffer);
        }
        //Cloud
        if (CID22 == 601) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[57])));
          playcomplete(buffer);
        }
        //Corrin
        if (CID22 == 602) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[58])));
          playcomplete(buffer);
        }
        //Bayonetta
        if (CID22 == 603) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[59])));
          playcomplete(buffer);
        }
        //Inkling Girl
        if (CID22 == 62 || CID22 == 607 || CID22 == 873 || CID22 == 898)
        //if (CID == 65544)  
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[60])));
          playcomplete(buffer);
        }
        //Inkling Boy
        if (CID22 == 63 || CID22 == 608 || CID22 == 874)
        //if (CID == 131080) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[61])));
          playcomplete(buffer);
        }
        //Squid
        if (CID22 == 64 || CID22 == 609 || CID22 == 875)
        //if (CID == 196616)  
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[62])));
          playcomplete(buffer);
        }
        //Chibi
        if (CID22 == 49186) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[63])));
          playcomplete(buffer);
        }         
        //Wolf Link
        if (CID22 == 591)
        //if (CID == 769) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[65])));
          playcomplete(buffer);
        }
        //Robotnik
        if (CID22 == 2870272106 || CID22 == 65535) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[66])));
          playcomplete(buffer);
        }
        //Guardian
        if (CID22 == 853)
        //if (CID == 16385) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[67])));
          playcomplete(buffer);
        }
        //Bokoblin
        if (CID22 == 860)
        //if (CID == 16641) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[68])));
          playcomplete(buffer);
        }
        //Toad
        if (CID22 == 56)
        //if (CID == 2560) 
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[69])));
          playcomplete(buffer);
        }        
        //Green Yarn Yoshi
        if (CID22 == 65)
        //if (CID == 33620736)
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[70])));
          playcomplete(buffer);
        }   
        //Pink Yarn Yoshi
        if (CID22 == 66)
        //if (CID == 33620736)
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[71])));
          playcomplete(buffer);
        }  
        //Blue Yarn Yoshi
        if (CID22 == 67)
        //if (CID == 33620736)
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[72])));
          playcomplete(buffer);
        }  
        //Mega Yarn Yoshi
        if (CID22 == 574)
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[73])));
          playcomplete(buffer);
        }              
        //Silver Mario
        if (CID22 == 61)
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[74])));
          playcomplete(buffer);
        }
        //Gold Mario
        if (CID22 == 60)
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[75])));
          playcomplete(buffer);
        }        
        //Toon Zelda
        if (CID22 == 850)
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[76])));
          playcomplete(buffer);
        }   
            
        //Link Archer
        if (CID22 == 851)
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[77])));
          playcomplete(buffer);
        }       
        //Link Rider
        if (CID22 == 852)
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[78])));
          playcomplete(buffer);
        }     
        //Boo
        if (CID22 == 616)
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[79])));
          playcomplete(buffer);
        }    
        //Daisy
        if (CID22 == 614)
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[80])));
          playcomplete(buffer);
        }    
        //Waluigi
        if (CID22 == 615)
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[81])));
          playcomplete(buffer);
        }    
        //Gold Megaman
        if (CID22 == 600)
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[82])));
          playcomplete(buffer);
        }  
        //Waddle Dee
        if (CID22 == 599)
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[83])));
          playcomplete(buffer);
        }  
        //Alm
        if (CID22 == 864)
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[84])));
          playcomplete(buffer);
        }  
        //Celica
        if (CID22 == 865)
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[85])));
          playcomplete(buffer);
        }  
        //Callie
        if (CID22 == 605)
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[86])));
          playcomplete(buffer);
        }  
        //Marie
        if (CID22 == 606)
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[87])));
          playcomplete(buffer);
        }  
        //Cloud2
        if (CID22 == 866)
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[88])));
          playcomplete(buffer);
        }  
        //Bayonetta2
        if (CID22 == 868)
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[89])));
          playcomplete(buffer);
        }  
        //Corrin2
        if (CID22 == 867)
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[90])));
          playcomplete(buffer);
        }  
        //Pikmin
        if (CID22 == 863)
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[91])));
          playcomplete(buffer);
        }   
        //Koopa Troopa
        if (CID22 == 872)
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[92])));
          playcomplete(buffer);
        }  
        //Goomba
        if (CID22 == 871)
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[93])));
          playcomplete(buffer);
        }          
        //Metroid
        if (CID22 == 870)
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[94])));
          playcomplete(buffer);
        }         
        //Tiki
        if (CID22 == 880)
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[95])));
          playcomplete(buffer);
        }  
        //Chrom
        if (CID22 == 879)
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[96])));
          playcomplete(buffer);
        }  
        //Daruk
        if (CID22 == 856)
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[97])));
          playcomplete(buffer);
        }  
        //Mipha
        if (CID22 == 858)
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[98])));
          playcomplete(buffer);
        }   
        //Revali
        if (CID22 == 859)
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[99])));
          playcomplete(buffer);
        }
        //Urbosa
        if (CID22 == 857)
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[100])));
          playcomplete(buffer);
        } 
        //Detective Pikachu
        if (CID22 == 885)
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[101])));
          playcomplete(buffer);
        }  
        //Dark Souls
        if (CID22 == 888)
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[102])));
          playcomplete(buffer);
        }  
        //Wolf
        if (CID22 == 894)
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[103])));
          playcomplete(buffer);
        }  
        //Ridley
        if (CID22 == 895)
        {strcpy_P(buffer, (char*)pgm_read_word(&(intro_table[104])));
          playcomplete(buffer);
        }
        
        
      }
    }
    else 
    {
      //if (currentcard == lastcard) 
      //{
       // Serial.println("CID else");
        wave.stop();
      //}  
      lastcard = 999999999;
      currentcard = 999999998;
      songplaying = false;
    }
  } 

   //If the Amiibo is gone, stop the song.
  else 
    {
      //if (currentcard == lastcard) 
      //{
        //Serial.println("UID else");
        wave.stop();
      //}  
      lastcard = 999999999;
      currentcard = 999999998;
      songplaying = false;
    }  
}

/////////////////////////////////// HELPERS

/*
* print error message and halt
*/
void error_P(const char *str) {
  PgmPrint("Error: ");
  SerialPrint_P(str);
  sdErrorCheck();
  while(1);
}
/*
* print error message and halt if SD I/O error
*/
void sdErrorCheck(void) {
  if (!card.errorCode()) return;
  PgmPrint("\r\nSD I/O error: ");
  Serial.print(card.errorCode(), HEX);
  PgmPrint(", ");
  Serial.println(card.errorData(), HEX);
  while(1);
}
/*
* Play a file and wait for it to complete
*/
void playcomplete(char *name) {
  playfile(name);
  while (wave.isplaying);
  
  // see if an error occurred while playing
  sdErrorCheck();
}
/*
* Open and start playing a WAV file
*/
void playfile(char *name) {
//  unsigned long start = millis();
//  unsigned long timer;
  if (wave.isplaying) {// already playing something, so stop it!
    wave.stop(); // stop it
  }
//  timer = millis();
//  Serial.println(timer - start);
  if (!file.open(root, name)) {
    PgmPrint("Couldn't open file ");
    Serial.print(name);
    PgmPrint("\n");
    return;
  }
//  timer = millis();
//  Serial.println(timer - start);
  if (!wave.create(file)) {
    PgmPrintln("Not a valid WAV");
    return;
  }
//  timer = millis();
//  Serial.println(timer - start);
  // ok time to play!
  wave.play();
//    timer = millis();
//    Serial.println(timer - start);
}
