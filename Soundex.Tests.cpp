#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
  char soundex[5];
  generateSoundex("AX", soundex);
  EXPECT_STREQ(soundex,"A200");
  //ASSERT_EQ(soundex,"A200");
}
TEST(SoudexTestsuite, NumbersWithCharacters) {
  char soundex[5];
  generateSoundex("17AK", soundex);
  EXPECT_STREQ(soundex,"1200");
  
}

TEST(SoudexTestsuite, NumbersWithLongCharacters) {

  char soundex[5];
  generateSoundex("APOO27", soundex);
  EXPECT_STREQ(soundex,"A100");
  
}



