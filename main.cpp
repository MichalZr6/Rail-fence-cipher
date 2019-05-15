#include <iostream>
#include <string>
#include <map>
#include <vector>

std::string encode_rail_fence_cipher(std::string str, int n)
{
    std::string ret_str = "";
    std::map<int, std::string> railed_strings_map;
    int j=0, k=1;

    for(size_t i=0; i < str.size(); i++)
    {
        if(i > 0 && i%(n-1) == 0)
            k *= -1;
        railed_strings_map[j] += str[i];
        j += k;
    }

    for(auto const &it : railed_strings_map)
        ret_str += it.second;

    return ret_str;
}

std::vector<int> get_len_coded_lines(const std::string &str, const int &n)
{
    std::vector<int> ret_vec(n, 0);
    int j=0, k=1;

    for(size_t i=0; i < str.size(); i++)
    {
        if(i > 0 && i%(n-1) == 0)
            k *= -1;
        ret_vec[j]++;
        j += k;
    }

    return ret_vec;
}

std::string decode_rail_fence_cipher(std::string str, int n)
{
    std::string ret_str = "";
    std::map<int, std::string> railed_strings_map;
    int j=0, k=1;
    std::vector<int> coded_vec_len = get_len_coded_lines(str, n);

    size_t str_pos = 0;

    for(int i=0; i<n; i++)
    {
        railed_strings_map[i] = str.substr(str_pos, coded_vec_len[i]);
        str_pos += coded_vec_len[i];
    }

    for(size_t i=0; i < str.size(); i++)
    {
        if(i > 0 && i%(n-1) == 0)
            k *= -1;
        ret_str += railed_strings_map[j][0];
        railed_strings_map[j].erase(0, 1);
        j += k;
    }

    return ret_str;
}

int main()
{
    std::cout << decode_rail_fence_cipher(encode_rail_fence_cipher("WEAREDISCOVEREDFLEEATONCE", 3), 3) << std::endl;
    return 0;
}
