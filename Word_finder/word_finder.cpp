#include <iostream>
#include <vector>
#include <string>

void vectorstring_to_vectorchar (const std::vector<std::string>& v, std::vector<char>& vout)
{

    vout.clear();

    for (int i = 0; i < v.size(); i++)
    {
        std::string s = v[i];

        for (int j = 0; j < s.size(); j++)
        {
            vout.push_back(s[j]);
        }
    }

}

void string_to_char(const std::string& s, std::vector<char>& v)
{

    v.clear();

    for (int i = 0; i < s.size(); i++)
    {
        v.push_back(s[i]);
    }

}

void pick_row(const std::vector<char>& v, int rowlen, int n, std::vector<char>& vout)
{

    vout.clear();

    for (int i = 0; i < rowlen; i++)
    {
        vout.push_back(v[n * rowlen + i]);
    }

}

void pick_col(const std::vector<char>& v, int rowlen, int n, std::vector<char>& vout)
{

    vout.clear();

    for (int i = 0; i < rowlen; i++)
    {
        vout.push_back(v[i * rowlen + n]);
    }

}

bool check_one_word(const std::vector<char>& v, const std::vector<char>& word, int n)
{
    
    int i = 0;

    for (int j = 0; j < word.size(); j++)
    {
        if (v[n + j] != word[j])
        {
            i++;
        }
    }

    if (i == 0)
    {
        return 1;
    }

    return 0;

}

void check_words(
    const std::vector<char>& v, 
    const std::vector<std::string>& words,
    int rowlen, int rc, int row_or_col, 
    std::vector<int>& check_result,
    std::vector<int>& found_word)
{

    for (int w = 0; w < words.size(); w++)
    {
        std::vector<char> picked_word;
        string_to_char(words[w], picked_word);

        for (int i = 0; i + picked_word.size() <= v.size(); i++)
        {
            if (check_one_word(v, picked_word, i))
            {
                for (int j = 0; j < picked_word.size(); j++)
                {
                    if (row_or_col == 0)
                    {
                        check_result[rc * rowlen + i + j] = 1;
                    }
                    if (row_or_col == 1)
                    {
                        check_result[(i + j) * rowlen + rc] = 1;
                    }
                    found_word[w] = 1;
                }
            }
        }
    }

}

void find_words(
    const std::vector<std::string>& grid, 
    const std::vector<std::string>& words,
    std::vector<std::string>& solution,
    std::vector<std::string>& not_found)
{

    solution = grid;
    not_found.clear();

    int rowlen = grid[0].size();
    int collen = grid.size();
    
    std::vector<char> grid_char;
    vectorstring_to_vectorchar(grid, grid_char);

    std::vector<int> check_result;
    for (int i = 1; i <= grid_char.size(); i++)
    {
        check_result.push_back(0);
    }

    std::vector<int> found_word;
    for (int i = 1; i <= words.size(); i++)
    {
        found_word.push_back(0);
    }
    
    std::vector<char> picked_row;
    for (int i = 0; i < collen; i++)
    {
        pick_row(grid_char, rowlen, i, picked_row);
        check_words(picked_row, words, rowlen, i, 0, check_result, found_word);
    }
    
    std::vector<char> picked_col;
    for (int i = 0; i < rowlen; i++)
    {
        pick_col(grid_char, rowlen, i, picked_col);
        check_words(picked_col, words, rowlen, i, 1, check_result, found_word);
    }

    for (int i = 0; i < grid_char.size(); i++)
    {
        if (check_result[i] == 0)
        {
            std::string s = solution[i / rowlen];
            s[i % rowlen] = '#';
            solution[i / rowlen] = s;
        }
    }

    for (int i = 0; i < words.size(); i++)
    {
        if (found_word[i] == 0)
        {
            not_found.push_back(words[i]);
        }
    }

}

int main()
{

    std::vector<std::string> grid = 
    {
        "xappleg",
        "dzeazkg",
        "zwazzbx",
        "dxnqzoy",
        "qyueytp",
        "pythtyg"
    };

    std::vector<std::string> words = {"peanut", "bot", "mango", "apple", "cinnamon"};
    std::vector<std::string> solution;
    std::vector<std::string> not_found;

    find_words(grid, words, solution, not_found); 

    std::vector<std::string> expected_solution = 
    {
        "#apple#",
        "##e####",
        "##a##b#",
        "##n##o#",
        "##u##t#",
        "##t####"
    };

    std::vector<std::string> expected_not_found = {"mango", "cinnamon"};

    if( (solution == expected_solution) && (not_found == expected_not_found) )
    {
        std::cout << "test passed" << std::endl;
    }
    else
    {
        std::cout << "test failed" << std::endl;
    }

    std::cout << "solution:" << std::endl;
    for(int i = 0; i < solution.size(); i++)
    {
        std::cout << solution[i] << std::endl;
    }

    std::cout << "not found:" << std::endl;
    for(int i = 0; i < not_found.size(); i++)
    {
        std::cout << not_found[i] << std::endl;
    }

}