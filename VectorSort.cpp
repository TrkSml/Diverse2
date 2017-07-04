// Sorting a vector recursively
// using only vectors
//
// @author: Tarek Samaali
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <typeinfo>

#define EXIT_SUCCESS 0
#define RANGE_RANDOM 1000
#define LENGTH 20

using namespace std ;


vector<int>::iterator recMin(std::vector<int>::iterator begin, std::vector<int>::iterator end, vector<int>::iterator min) // private
{
    if (begin != end)
    {
        if (*min>*begin) min=begin ;
        return recMin(++begin, end, min);
    }
    return min;
}


int recMinPos(vector<int> vect,vector<int>::iterator global_begin, vector<int>::iterator begin, vector<int>::iterator end, int min)
{
    if (begin != end)
    {
        if (vect[min]>*begin) min=std::distance(global_begin, begin ) ;
        return recMinPos(vect,global_begin,++begin, end, min);
    }
    return min;
}


void displayVector(vector<int> vect){
    vector<int>::iterator itg;
    for(itg = vect.begin(); itg != vect.end(); itg++)
    {
        std::cout << *itg << " ";
    }
    std::cout << "\n";
}


vector<int> concat(vector<int> v1,vector<int> v2){
    v1.insert(v1.end(),v2.begin(),v2.end());
    return v1 ;
}


vector<int> Sort(vector<int> vect){

    if (vect.size()==1) return vect ;

    vector<int>::iterator begin=vect.begin();
    vector<int>::iterator end=vect.end();
    vector<int>::iterator global_begin=begin;

    int min_position=recMinPos(vect,global_begin,begin,end,0);
    swap(vect.at(0),vect.at(min_position));

    std::vector<int> front;
    front.push_back(vect[0]);

    return concat(front,Sort(vector<int>(++vect.begin(),vect.end()))) ;

}

int main(int argc, char** argv){

vector< int > vector1, vector2;

/* Fill both the two vectors randomly */
for (int i = 0; i < LENGTH; ++i)
{
    vector1.push_back(rand()%RANGE_RANDOM) ;
}

for (int i = 0; i < LENGTH; ++i)
{
    vector2.push_back(rand()%RANGE_RANDOM) ;
}


/* Display the content of the two vectors */

displayVector(vector1);
displayVector(vector2);

/* Sort and display the two concatenated vectors */
std::cout << "vector1 + Vector2 sorted : " << "\n";
displayVector(Sort(concat(vector1,vector2)));

return EXIT_SUCCESS;
}
