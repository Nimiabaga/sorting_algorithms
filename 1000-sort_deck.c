#include "deck.h"
#include <stdio.h>

int compare_strings(const char *str1, const char *str2);
char get_numeric_value(deck_node_t *card);
void sort_by_card(deck_node_t **deck);
void sort_by_value(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * compare_strings - Compare two strings.
 * @str1: The first string.
 * @str2: The second string.
 * Return: 0 if str1 and str2 are equal, positive if str1 >
 * str2, negative if str1 < str2.
 */
int compare_strings(const char *str1, const char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	return (*str1 - *str2);
}

/**
 * get_numeric_value - Get the numeric value of a card.
 * @card: Pointer to a deck_node_t card.
 *
 * Return: Numeric value of the card.
 */
char get_numeric_value(deck_node_t *card)
{
	if (compare_strings(card->card->value, "Ace") == 0)
		return (0);
	if (compare_strings(card->card->value, "1") == 0)
		return (1);
	if (compare_strings(card->card->value, "2") == 0)
		return (2);
	if (compare_strings(card->card->value, "3") == 0)
		return (3);
	if (compare_strings(card->card->value, "4") == 0)
		return (4);
	if (compare_strings(card->card->value, "5") == 0)
		return (5);
	if (compare_strings(card->card->value, "6") == 0)
		return (6);
	if (compare_strings(card->card->value, "7") == 0)
		return (7);
	if (compare_strings(card->card->value, "8") == 0)
		return (8);
	if (compare_strings(card->card->value, "9") == 0)
		return (9);
	if (compare_strings(card->card->value, "10") == 0)
		return (10);
	if (compare_strings(card->card->value, "Jack") == 0)
		return (11);
	if (compare_strings(card->card->value, "Queen") == 0)
		return (12);

	return (13);
}

/**
 * sort_by_card - Sort a deck of cards based on their kind.
 * @deck: Pointer to the deck.
 */
void sort_by_card(deck_node_t **deck)
{
	deck_node_t *current, *next, *previous;

	for (current = (*deck)->next; current != NULL; current = next)
	{
		next = current->next;
		previous = current->prev;

		while (previous != NULL && previous->card->kind > current->card->kind)
		{
			previous->next = current->next;

			if (current->next != NULL)
				current->next->prev = previous;

			current->prev = previous->prev;
			current->next = previous;

			if (previous->prev != NULL)
				previous->prev->next = current;
			else
				*deck = current;

			previous->prev = current;
			previous = current->prev;
		}
	}
}

/**
 * sort_by_value - Sort a deck of cards based on their numeric value.
 * @deck: Pointer to the deck.
 */
void sort_by_value(deck_node_t **deck)
{
	deck_node_t *current, *next, *previous;

	for (current = (*deck)->next; current != NULL; current = next)
	{
		next = current->next;
		previous = current->prev;

		while (previous != NULL &&
				previous->card->kind == current->card->kind &&
				get_numeric_value(previous) > get_numeric_value(current))
		{
			previous->next = current->next;

			if (current->next != NULL)
				current->next->prev = previous;

			current->prev = previous->prev;
			current->next = previous;

			if (previous->prev != NULL)
				previous->prev->next = current;
			else
				*deck = current;

			previous->prev = current;
			previous = current->prev;
		}
	}
}

/**
 * sort_deck - Sort a deck of cards based on kind and numeric value.
 * @deck: Pointer to the deck.
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	sort_by_card(deck);
	sort_by_value(deck);
}

