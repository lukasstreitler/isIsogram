#include "vendor/unity.h"
#include "../src/isogram.h"
#include "vendor/unity_internals.h"
#include <stdlib.h>
#include <string.h>

void test_empty_string(void)
{
   TEST_ASSERT_TRUE(is_isogram(""));
}
void test_short_isogram_word(){
    TEST_ASSERT_TRUE(is_isogram("Auto"));
}
void test_butter_isogram(){
    TEST_ASSERT_FALSE(is_isogram("butter"));
}
void test_long_isogram(){
    TEST_ASSERT_TRUE(is_isogram("Dialogschwerpunkt"));
}
void test_no_long_isogram(){
    TEST_ASSERT_FALSE(is_isogram("sdfasdfasfasfasfasfasdfasdfasdf"));
}
void test_aal()
{
    TEST_ASSERT_FALSE(is_isogram("Aal"));
}
void test_leerzeichen()
{
    TEST_ASSERT_FALSE(is_isogram("Dialog schwer punkt"));
}
int main(void)
{
   UnityBegin("isIsogram");

   RUN_TEST(test_empty_string);
   RUN_TEST(test_short_isogram_word);
   RUN_TEST(test_butter_isogram);
   RUN_TEST(test_long_isogram);
   RUN_TEST(test_no_long_isogram);
   RUN_TEST(test_aal);
   RUN_TEST(test_leerzeichen);
   UnityEnd();
   return 0;

}
