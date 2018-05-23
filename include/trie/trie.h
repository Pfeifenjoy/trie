#ifndef TRIE_H_QCLIV8BD
#define TRIE_H_QCLIV8BD

#include "stdbool.h"
#include "unistd.h"

typedef ssize_t trie_value;

struct trie {
	char symbol;

	//value
	trie_value value;
	bool is_end;

	//children
	unsigned char children_count;
	unsigned char children_size;
	struct trie *children;
};

struct trie *make_trie();
void trie_free(struct trie *);
void trie_set(struct trie *, const char *, trie_value);
trie_value trie_search(const struct trie *, const char *);
void trie_delete(struct trie *trie, const char *key);
void trie_refresh(struct trie *);

#endif /* end of include guard: TRIE_H_QCLIV8BD */
