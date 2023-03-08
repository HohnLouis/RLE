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

void RLE_compress(string &text)
{
    int cnt = 1;
    string res = "";
    text = "0" + text + "0";
    for(int i = 1; i < text.size(); i++)
    {
        if(text[i] == text[i - 1])
        {
            cnt++;
            continue;
        }
        if(cnt <= 2) for(int j = 1; j <= cnt; j++) res += text[i - 1];
        else res += stringize(cnt) + text[i - 1];
        cnt = 1;
    }
    res.erase(0, 1);
    text = res;
}
//nen xau

int numberize(string &s)
{
    int res = 0;
    for(int i = 0; i < s.size(); i++)
        res = res * 10 + (s[i] - 48);
    return res;
}

void RLE_extract(string &text)
{
    string res = "", cnt = "";
    for(int i = 0; i < text.size(); i++)
    {
        if(text[i] >= '0' && text[i] <= '9')
        {
            cnt += text[i];
            continue;
        }
        if(cnt == "") res += text[i];
        for(int j = 1; j <= numberize(cnt); j++) res += text[i];
        cnt = "";
    }
    text = res;
}
//giai nen RLE

int main()
{
    cin >> essay >> ques;
    ques == 0 ? RLE_compress(essay) : RLE_extract(essay);
    cout << essay;
    return 0;
}
