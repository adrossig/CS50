#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //TODO: Prompt for start size
    int population_begin;
    do
    {
        population_begin = get_int("Start size?\n");
    }
    while (population_begin < 9);
    // TODO: Prompt for end size
    int population_end;
    do
    {
        population_end = get_int("End size?\n");
    }
    while (population_begin > population_end);
    // TODO: Calculate number of years until we reach threshold
    int years = 0;
    while (population_begin < population_end)
    {
        population_begin += (population_begin / 3) - (population_begin / 4);
        years++;
    }
    // TODO: Print number of years
    printf("Years: %d\n", years);
}
