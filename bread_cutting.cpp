#include<bits/stdc++.h>
using namespace std;


// returns the minimum of two integers
int min(int a, int b){
    return (a < b) ? a : b;
}

// returns the minimum cost of cutting a cake piece starting from length i to j
int find_minimum_cost(int i, int j, int cake[]){

    int mn = j-i, x = 0;

    for(int k = i+1; k < j; k++){
        // cake[k] > cake[k-1] indicates that the cake piece has a cutpoint on k
        if(cake[k]>cake[k-1]){
            mn = min(mn, find_minimum_cost(i, k, cake)+find_minimum_cost(k, j, cake));

            // taking count of the cuts made in the cake
            x++;
        }
    }

    // x == 0 indicates that the cake piece has 0 cutpoints in it
    if(!x) return 0;

    // x == 1 indicates that the cake piece has 1 cutpoint in it
    else if(x == 1) return j-i;


    return j-i+mn;
}

int main()
{
    // the cake size
    cout<<"Enter the cake size"<<endl;
    int cake_size;
    scanf("%d", &cake_size);

    // making a cake, initially with no cutpoints, hence, each index is 0
    int cake[cake_size+1];
    for(int i = 0; i <= cake_size; i++){
        cake[i] = 0;
    }

    // how many cutpoints the cake has
    cout<<"Enter the number of cutpoints"<<endl;
    int number_of_cutpoints;
    scanf("%d", &number_of_cutpoints);

    cout<<"Enter the cutpoints of bread"<<endl;
    int cutpoint;
    for(int i = 0; i < number_of_cutpoints; i++){
        scanf("%d", &cutpoint);

        // saving the index of the cutpoint
        cake[cutpoint] = 1;
    }

    // taking count of how many cutpoints there are starting from length 0 to i
    for(int i = 1; i <= cake_size; i++){
        cake[i] += cake[i-1];
    }

    // find the minimum cost of cutting the whole cake
    int minimum_cost = find_minimum_cost(0, cake_size, cake);
    printf("The minimum cost of cutting the bread is %d.\n", minimum_cost);

    return 0;
}
