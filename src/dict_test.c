/**
 * Copyright (c) 2015, Chao Wang <hit9@icloud.com>
 */

#include <assert.h>
#include <string.h>
#include "test.h"
#include "errors.h"
#include "dict.h"

void
case_dict_set()
{
    struct dict *dict = dict();
    char *key = "key", *val = "val";
    size_t len = strlen(key);
    assert(dict_set(dict, key, len, val) == ERR_OK);
    assert(dict->size == 1);
    char *val_ = "val_";
    assert(dict_get(dict, key, len) == val);
    assert(dict_set(dict, key, len, val_) == ERR_OK);
    assert(dict_get(dict, key, len) == val_);
    dict_free(dict);
}

void
case_dict_get()
{
    struct dict *dict = dict();
    char *key = "key", *val = "val";
    size_t len = strlen(key);
    assert(dict_set(dict, key, len, val) == ERR_OK);
    assert(dict->size == 1);
    assert(dict_get(dict, key, len) == val);
    assert(dict_get(dict, key, 1) == NULL);
    assert(dict_get(dict, key, 8) == NULL);
    dict_free(dict);
}

void
case_dict_pop()
{
    struct dict *dict = dict();
    char *key = "key", *val = "val";
    size_t len = strlen(key);
    assert(dict_set(dict, key, len, val) == ERR_OK);
    assert(dict->size == 1);
    assert(dict_pop(dict, key, len) == val);
    assert(dict->size == 0);
    assert(dict_pop(dict, key, len) == NULL);
    assert(dict->size == 0);
    dict_free(dict);
}

void
case_dict_has()
{
    struct dict *dict = dict();
    char *key = "key", *val = "val";
    size_t len = strlen(key);
    assert(dict_set(dict, key, len, val) == ERR_OK);
    assert(!dict_has(dict, "not exist", 9));
    assert(dict_has(dict, key, len));
    dict_free(dict);
}

void
case_dict_clear()
{
    struct dict *dict = dict();
    assert(dict_set(dict, "key1", 4, "val1") == ERR_OK);
    assert(dict_set(dict, "key2", 4, "val2") == ERR_OK);
    assert(dict_set(dict, "key3", 4, "val3") == ERR_OK);
    assert(dict_set(dict, "key4", 4, "val4") == ERR_OK);
    assert(dict->size == 4);
    dict_clear(dict);
    assert(dict->size == 0);
    dict_free(dict);
}

void
case_dict_resize()
{
    struct dict *dict = dict();
    assert(dict_set(dict, "key1", 4, "val1") == ERR_OK);
    assert(dict_set(dict, "key2", 4, "val2") == ERR_OK);
    assert(dict_set(dict, "key3", 4, "val3") == ERR_OK);
    assert(dict_set(dict, "key4", 4, "val4") == ERR_OK);
    assert(dict->size == 4);
    assert(dict->idx == 0);
    assert(dict_set(dict, "key5", 4, "val5") == ERR_OK);
    assert(dict_set(dict, "key6", 4, "val6") == ERR_OK);
    assert(dict->size == 6);
    assert(dict->idx == 1);
    dict_free(dict);
}

void
case_dict_iterator()
{
    struct dict *dict = dict();
    char *key1 = "key1"; size_t len1 = 4;
    char *key2 = "key2"; size_t len2 = 4;
    char *key3 = "key3"; size_t len3 = 4;
    char *key4 = "key4"; size_t len4 = 4;
    char *key5 = "key5"; size_t len5 = 4;
    char *key6 = "key6"; size_t len6 = 4;
    assert(dict_set(dict, key1, len1, "val1") == ERR_OK);
    assert(dict_set(dict, key2, len2, "val2") == ERR_OK);
    assert(dict_set(dict, key3, len3, "val3") == ERR_OK);
    assert(dict_set(dict, key4, len4, "val4") == ERR_OK);
    assert(dict_set(dict, key5, len5, "val5") == ERR_OK);
    assert(dict_set(dict, key6, len6, "val6") == ERR_OK);

    struct dict_iterator *iterator = dict_iterator(dict);
    assert(strncmp(dict_iterator_next(iterator)->key, key1, len1) == 0);
    assert(strncmp(dict_iterator_next(iterator)->key, key2, len2) == 0);
    assert(strncmp(dict_iterator_next(iterator)->key, key3, len3) == 0);
    assert(strncmp(dict_iterator_next(iterator)->key, key4, len4) == 0);
    assert(strncmp(dict_iterator_next(iterator)->key, key5, len5) == 0);
    assert(strncmp(dict_iterator_next(iterator)->key, key6, len6) == 0);
    dict_iterator_free(iterator);
    dict_free(dict);
}
