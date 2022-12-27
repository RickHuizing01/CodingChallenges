#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct pairlist {
    int *data; /* pointer to list with pairs */
    int length; /* lenght of list */
} pairlist;


bool is_distinct(int first, int input_length, int *input) {
    if (input_length == 0) {
        /* there are no pairs yet, so validation is not required. */
        return true;
    }

    for (int x = 0; x < input_length; x+=2) {
        /* since we already know that all elements in a pair add up to 17, 
        we only need to check if first is present in one of the already existing pairs. */
        if (first == input[x] || first == input[x + 1]) {
            /* found double or inversed pair */
            return false;
        }
    }
    /* no double or inversed pairs found */
    return true;
}

pairlist find_unique_eval_pairs(int evaluator, int *input, int input_size) {
    /* The required memory space is determined by the (theoretical) maximum amount of pairs to be found based on the size of the input. */
    int *pairs = malloc(sizeof(int) * 2 * input_size * input_size);

    if (!pairs)
    {
        pairlist error = { NULL, 0 };
        return error;
    }

    int pairs_index = 0;
    for (int x = 0; x <= input_size; x++) 
    {
        for (int y = 0; y <= input_size; y++) 
        {
            /* Since c makes use of short circuit evaluation, the is_distinct function won't be called if input[x] + input[y] != evaluator. */
            if (input[x] + input[y] == evaluator && is_distinct(input[x], pairs_index, pairs) == true)
            {
                pairs[pairs_index] = input[x];
                pairs[pairs_index + 1] = input[y];
                pairs_index+=2;
            } 
        }
    }

    /* free allocated memory that is not used anymore. */
    if (pairs_index < input_size * input_size * 2) {
        pairs = realloc(pairs, sizeof(int) * pairs_index);
    }

    pairlist result = { pairs, pairs_index };
    return result;
}


int main() {
    int input[] = {5, 10, 7, 12, 5, 9, 3, 7, 1, 16, 99, 20, 14};
    const int input_size = (int) sizeof(input) / sizeof(int);
    const int eval = 17;

    pairlist pairs = find_unique_eval_pairs(eval, input, input_size);

    for (int x = 0; x < pairs.length; x+=2) {
        printf("%d and %d\n", pairs.data[x], pairs.data[x + 1]);
    }
}