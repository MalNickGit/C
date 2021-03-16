#include "Unity/src/unity.h"
#include "test.h"

void testf() {
  TEST_ASSERT_EQUAL_INT(5, add(2, 3));
  TEST_ASSERT_EQUAL_INT(-5, add(-2, -3));
  TEST_ASSERT_EQUAL_INT(3, add(5, -2));
  TEST_ASSERT_EQUAL_INT(3, add(-2, 5));
  TEST_ASSERT_EQUAL_INT(3, add(3, 0));
  TEST_ASSERT_EQUAL_INT(3, add(0, 3));
  TEST_ASSERT_EQUAL_INT(0, add(0, 0));
}

void setUp() { 

}

void tearDown() {

}

void main() {
  UNITY_BEGIN();
  RUN_TEST(testf);
  return UNITY_END();
}
