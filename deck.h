#ifndef DECK_H
#define DECK_H

/**
 * enum kind_e - Represents the kinds of cards.
 * @SPADE: Spade
 * @HEART: Heart
 * @CLUB: Club
 * @DIAMOND: Diamond
 */
typedef enum kind_e
{
	SPADE,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Represents a playing card.
 * @value: The value of the card (from "Ace" to "King").
 * @kind: The kind of the card (SPADE, HEART, CLUB, DIAMOND).
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Represents a node in a deck of cards.
 * @card: Pointer to the card of the node.
 * @prev: Pointer to the previous node in the list.
 * @next: Pointer to the next node in the list.
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

int compare_strings(const char *str1, const char *str2);
char get_numeric_value(deck_node_t *card);
void sort_by_card(deck_node_t **deck);
void sort_by_value(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

#endif /* DECK_H */

