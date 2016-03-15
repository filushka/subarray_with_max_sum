/*
most_frequent_element_from_array -- this program finds subarray with maxumum
possible sum of it's elements in the given array
Copyright (C) <2016>  <Elena Filenko>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <iostream>
#include <vector>

using namespace std;
/// For the purpose of possible reduction in number of operation required
/// for calculating maximum sum subarray inside array
/// we consider consequent negative or consequent positive elements as one element equal to
/// consequetive elements SUM
///
/// struct node created in case if we need to calculate indexes for the max sum rray


///
/// \brief The node struct
///
struct node
{
    unsigned int beg_index;
    unsigned int end_index;
    int sum;
    unsigned int index;
};

struct max_sum_array_node
{
    int sum;
    int beg;
    int end;
};


int array[ 20 ] = { -1, 2, 3,4, 0,-1,-10, -20, 4, -1,
                    0 ,-9, 6, 89, 1, 0, 0, -1, -2, 1 };

///
/// \brief get_node -- fills node n
/// \param array -- pointer to array
/// \param beg -- first index of array
/// \param end -- last index of aray
/// \param index -- index of element in the vector
/// \param n -- node n with all fields filled out
///
void get_node( int* array, int beg, int end, int index, node* n )
{
    int sum = array[ beg ];
    int i = beg+1;

    if( sum < 0 )
    {
        while( i <= end )
        {
            if(  array[ i ] < 0)
            {
                sum +=array[ i ];
                ++i;
            }
            else
                break;
        }
    }
    else
    {
        while( i <= end )
        {
            if(  array[ i ] >= 0)
            {
                sum +=array[ i ];
                ++i;
            }
            else
                break;
        }
    }

    n->beg_index = beg;
    n->end_index = i - 1;
    n->sum = sum;
    n->index = index;
}

///
/// \brief SUM -- sum of all array elements
/// \param array -- pointer to an integer array
/// \param array_size -- array_size -- number of elements in the array
/// \return
///
int SUM( int* array, int array_size )
{
    int res = 0;
    for(int i = 0; i < array_size; i++ )
        res += array[ i ];

    return res;
}

///
/// \brief max_sum -
/// \param array pointer to integer array
/// \param array_size -- number of elements in the array
/// \return maximum sum of subsequent elements in the array
///
int max_sum( int* array, int array_size )
{
    int sum = 0;

    if( array_size == 1 )
        return array[ 0 ];
    else
    {
        int sum0 = SUM( array, array_size );
        int sum1 = max_sum( array, array_size - 1 );
        int sum2 = max_sum( &array[ 1 ], array_size - 1 );

        if( sum0 > sum1 )
        {
            if( sum0 > sum2)

                return sum0;
            else
                return sum2;
        }
        else
        {
            if( sum1 > sum2 )
                return sum1;
            else
                return sum2;
        }
    }
}

int main(int argc, char *argv[])
{
    vector< node* > vec;
    int beg = 0;
    int end = 19;
    int i = 0;

    while( beg <= end )
    {
        node* n = new node();
        get_node( array, beg, end, i, n );
        vec.push_back( n );
        beg = n->end_index + 1;
        ++i;
    }

    // number of elements in the vector
    cout << "vec.size()= " << vec.size() << "  i = " << i << endl;

    int arr[ 100 ];
    for( int k = 0; k < i; k++ )
        arr[ k] = (vec.at( k ))->sum;
    cout << max_sum( arr, i ) << endl;

    return 0;
}
