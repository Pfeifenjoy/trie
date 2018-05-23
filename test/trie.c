#include "trie/trie.h"
#include "stdlib.h"
#include "assert.h"

void simple_insertion() {
	struct trie *trie = make_trie();
	trie_set(trie, "foo", 42);
	assert(trie_search(trie, "foo") == 42);
	trie_free(trie);
}

void empty_key() {
	struct trie *trie = make_trie();
	trie_set(trie, "", 42);
	assert(trie_search(trie, "") == 42);
	trie_free(trie);
}

void two_keys() {
	struct trie *trie = make_trie();
	trie_set(trie, "foo", 42);
	trie_set(trie, "bar", 24);

	assert(trie_search(trie, "foo") == 42);
	assert(trie_search(trie, "bar") == 24);
	trie_free(trie);
}

void two_keys_with_same_beginning() {
	struct trie *trie = make_trie();
	trie_set(trie, "blob", 42);
	trie_set(trie, "blab", 24);

	assert(trie_search(trie, "blob") == 42);
	assert(trie_search(trie, "blab") == 24);
	trie_free(trie);
}

void max_children() {
	struct trie *trie = make_trie();
	for(unsigned char i = 0; i < 8 * sizeof(unsigned char); ++i) {
		char key[2];
		key[0] = (char) i;
		key[1] = 0;
		trie_set(trie, key, (ssize_t) i);
	}
	for(unsigned char i = 0; i < 8 * sizeof(unsigned char); ++i) {
		char key[2];
		key[0] = (char) i;
		key[1] = 0;
		assert(trie_search(trie, key) == (ssize_t) i);
	}
	trie_free(trie);
}

int main(int argc, char *argv[]) {
	simple_insertion();
	empty_key();
	two_keys();
	two_keys_with_same_beginning();
	return 0;
}
