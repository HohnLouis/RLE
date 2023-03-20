#include <bits/stdc++.h>

using namespace std;

string essay;
int ques;

string stringize(int &a)
{
    string res = "";
    while(a > 0)
    {
        res = char(a % 10 + 48) + res;
        a /= 10;
    }
    return res;
}

void RLE_compress(string &input)
{
    int cnt = 1;
    string res = "";
    input = "0" + input + "0";
    for(int i = 1; i < input.size(); i++)
    {
        if(input[i] == input[i - 1])
        {
            cnt++;
            continue;
        }
        if(cnt <= 2) for(int j = 1; j <= cnt; j++) res += input[i - 1];
        else res += stringize(cnt) + input[i - 1];
        cnt = 1;
    }
    res.erase(0, 1);
    input = res;
}
//nen xau

int numberize(string &s)
{
    int res = 0;
    for(int i = 0; i < s.size(); i++)
        res = res * 10 + (s[i] - 48);
    return res;
}

void RLE_extract(string &input)
{
    string res = "", cnt = "";
    for(int i = 0; i < input.size(); i++)
    {
        if(input[i] >= '0' && input[i] <= '9')
        {
            cnt += input[i];
            continue;
        }
        if(cnt == "") res += input[i];
        for(int j = 1; j <= numberize(cnt); j++) res += input[i];
        cnt = "";
    }
    input = res;
}
//giai nen RLE

int main()
{
    cout << "0 for compression and 1 for extraction: ";
    cin >> ques;
    cout << "\nPut your essay here: ";
    cin >> essay;
    ques == 0 ? RLE_compress(essay) : RLE_extract(essay);
    cout << "\nThe result is: " << essay;
    return 0;
}
