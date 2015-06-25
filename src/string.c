/**
 * Copyright (c) 2015, Chao Wang <hit9@icloud.com>
 */

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"

bool
string_empty(struct string *s)
{
    assert(s != NULL);

    if (s->len == 0) {
        assert(s->data == NULL);
        return true;
    } else {
        assert(s->data != NULL);
        return false;
    }
}

int
string_ncmp(struct string *s1, struct string *s2, uint32_t n)
{
    assert(s1 != NULL && s2 != NULL);
    return strncmp((char *)s1->data, (char *)s2->data, (size_t)n);
}

int
string_cmp(struct string *s1, struct string *s2)
{
    assert(s1 != NULL && s2 != NULL);

    if (s1->len > s2->len)
        return 1;

    if (s1->len < s2->len)
        return -1;

    return string_ncmp(s1, s2, s1->len);
}
