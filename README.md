[![Build Status](https://travis-ci.org/Pfeifenjoy/trie.h.svg?branch=master)](https://travis-ci.org/Pfeifenjoy/trie.h)

# Trie.h

A small library which implements tries in C.
The idea is that the trie only holds `ssize_t` values.
Thus it can be used as an index for an array.

E.g:
```
#include "trie/trie.h"

int main(const int argc, const char **argv) {
	char **array; // my array of string e.g.: { "bar", ... }

	struct trie *trie = make_trie();

	trie_set(trie, "foo", 0);
	
	array[trie_get(trie, "foo")]; //-> "bar"

	trie_free(trie);
}
```
