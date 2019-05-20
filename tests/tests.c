#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "../map.h"
#include "unity/unity.h"

/*
 * test_map_new verifies that map_new 
 * returns a new valid map.
 */
void
test_map_new(void)
{
    struct map *m = map_new(100);
    TEST_ASSERT_NOT_NULL(m);
    map_free(m);
}

/*
 * test_map_cap verifies that the default
 * size is used for a new map when a value
 * of zero is given.
 */
void
test_map_default_cap(void)
{
    int expected = DEFAULT_SIZE;
    struct map *m = map_new(0);
    TEST_ASSERT_EQUAL_INT(expected, m->cap);
    map_free(m);
}

/*
 * test_map_len verifies that the reported 
 * length of the map matches to the number 
 * of records added.
 */
void
test_map_len(void)
{
    int expected = 1;
    struct map *m = map_new(0);
    map_set(m, "animals", "[\"dog\", \"cat\", \"horse\"]");
    TEST_ASSERT_EQUAL_INT(expected, m->len);
    map_free(m);
}

/*
 * test_map_set verifies taht a value is 
 * able to be set.
 */
void
test_map_set(void)
{
    struct map *m = map_new(0);
    map_set(m, "doctor", "Quinn");
    char *doctor = (char *)map_get(m, "doctor");
    TEST_ASSERT_EQUAL_STRING("Quinn", doctor);
    map_free(m);
}

/*
 * test_map_del verifies that a given key is
 * able to be deleted.
 */
void
test_map_del(void)
{
    struct map *m = map_new(0);
    map_set(m, "key", "value");
    char *pre_del_value = (char *)map_get(m, "key");
    TEST_ASSERT_EQUAL_STRING("value", pre_del_value);
    map_del(m, "key");
    char *post_del_value = (char *)map_get(m, "key");
    TEST_ASSERT_EQUAL_STRING("", post_del_value);
    map_free(m);
}

/*
 * test_map_update verifies that a value is able
 * to be updated.
 */
void
test_map_update(void)
{
    struct map *m = map_new(0);
    int test_val = 10;
    map_set(m, "int", test_val);
    int int_val = (int)map_get(m, "int");
    TEST_ASSERT_EQUAL_INT(10, int_val);
    map_set(m, "int", test_val+1);
    int_val = (int)map_get(m, "int");
    TEST_ASSERT_EQUAL_INT(11, int_val);
    map_free(m);
}

/*
 * test_map_get_set_int verifies that an integer 
 * value is able to be set as a value.
 */
void
test_map_get_set_int(void)
{
    struct map *m = map_new(0);
    int test_val = 10;
    map_set(m, "int", test_val);
    int int_val = (int)map_get(m, "int");
    TEST_ASSERT_EQUAL_INT(10, int_val);
    map_free(m);
}

/*
 * test_map_get_set_double verifies that a 
 * double value is able to be set as a value.
 */
void
test_map_get_set_double(void)
{
    struct map *m = map_new(0);
    double test_val = 10;
    map_set(m, "double", &test_val);
    double *double_val = (double *)map_get(m, "double");
    map_free(m);
}

int
main(void)
{
	UNITY_BEGIN();

    RUN_TEST(test_map_new);
    RUN_TEST(test_map_default_cap);
    RUN_TEST(test_map_len);
    RUN_TEST(test_map_set);
    RUN_TEST(test_map_update);
    RUN_TEST(test_map_get_set_int);
    RUN_TEST(test_map_get_set_double);

    return UNITY_END();
}
