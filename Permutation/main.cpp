#include <iostream>
#include <string>
#include <utility>

/// @brief Permutation of a string, in here only printing operation is applied but another essential operations could be done.
/// @param S The input string
/// @param l the lower index required for the permutation
/// @param h the high index required for the permutation.
void Permutation(std::string& S, int l, int h)
{
    int i{};
    if( l == h)
        std::cout << S << "\n";
    else
    {
        for(i = l; i <= h; i++)
        {
            std::swap(S[l], S[i]);
            Permutation(S, l+1, h);
            std::swap(S[l], S[i]);
        }
    }
}

// TODO: Visit here again.
int main()
{
    std::string test{"ABCDEF"};
    Permutation(test, 0, test.size()-1);
}