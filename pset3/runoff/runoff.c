#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // TODO
        for (int j = 0; j < candidate_count; j++)
        {
            if (strcmp(name,candidates[j].name) == 0)
            {
                //um int referente a posição do candidato na lista de candidatos.
                preferences[voter][rank] = j;
                return true;
            }
        }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // TODO
    //itere todos os eleitores.
    for (int i = 0; i < voter_count; i++)
    {
        //itere todos os candidatos.
        for (int j = 0; j < candidate_count; j++)
        {
            //se o candidato não tiver sido eliminado incremente +1 a quantidade de votos.
            if (candidates[preferences[i][j]].eliminated == false)
            {
                candidates[preferences[i][j]].votes++;
                break;
            }
        }
    }
    //esta função não deve retornar nada.
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // TODO
    //itere todos os candidatos
    for (int j = 0; j < candidate_count; j++)
    {
        //se o candidato tiver mais que 50% do total dos votos.
        //print o nome do candidato e declare-o como vencedor retornando true.
        if (candidates[j].votes > (voter_count/2))
        {
            printf("%s\n", candidates[j].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // TODO
    int min  =  voter_count;
    //itere todos os candidatos.
    for (int j = 0; j < candidate_count; j++)
    {
        //se o candidato não tiver sido eliminado
        if (candidates[j].eliminated == false)
        {
            if (candidates[j].votes < min)
            {
                min =  candidates[j].votes;
            }
        }
    }

    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // TODO
    int running = 0;//contador de candidatos ainda concorrendo
    int tie_count = 0;//contador de empates
    for (int i = 0; i < candidate_count; i++)
    {
        /*se a quantidade de votos do candidatos for a minima
        e ele não tiver sido eliminado os contadores são incrementados*/
        if (candidates[i].votes == min)
        {
            tie_count ++;
        }
        if (candidates[i].eliminated == false)
        {
            running++;
        }
    }
    //se todos os candidatos concorrentes estiverem empatados
    //retorne true declarando a eleição empatada.
    if (running == tie_count)
        {
            return true;
        }
    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO
    //itere todos os candidatos
    for (int i = 0; i <  candidate_count; i++)
    {
        /*se o quantidade de votos do candidato for
        igual a menor quantidade de votos, este sera eliminado.*/
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    //esta função não deve retornar nada.
    return;
}
