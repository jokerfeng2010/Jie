#include<iostream>
#include<string>
using namespace std;
#define ms 200
char map[ms][ms];
struct pos{
	int x,y;
}q[ms*ms];
					//左       左上      上       上右      右     右下    下      下左
const int fx[][2] = {{0,-1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}}; 
const int fx1[][2] = {{0,-1}, {-1, 0}, {0, 1}, {1, 0}};
int main()
{
	int row, col, h=0, t=1;
	pos s, s1;
	cin >> row >> col >> s.x >> s.y;
	while (row != 0)
    {
		string str;
        for (int i = 0; i < row; ++i)
        {
			cin >> str;
			for (int j = 0; j < col; j++)
				map[i][j] = str[j];
        }
        --s.x; --s.y;
        if (!(s.x >=0 && s.y>=0 && s.x <row && s.y<col) || '.' == map[s.x][s.y])
        {
            printf("0\n");
            continue;
        }
		h = 0, t = 1;
		q[h] = s;
		while(h < t){
			s = q[h++];
			map[s.x][s.y] = 'A';
			for (int d = 0; d < 8; d++){
				s1.x = s.x + fx[d][0];
				s1.y = s.y + fx[d][1];
				if (s1.x >=0 && s1.y>=0 && s1.x <row && s1.y<col && map[s1.x][s1.y] == 'X'){
					q[t++] = s1;
				}
			}
		}
		int total = 0;
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)if (map[i][j] == 'A'){
				total += 4;
				for (int d = 0; d < 4; d++){
					s1.x = i + fx1[d][0];
					s1.y = j + fx1[d][1];
					if (s1.x >=0 && s1.y>=0 && s1.x <row && s1.y<col && map[s1.x][s1.y] == 'A')
						total--;
				}
			}
		cout << total << endl;
		cin >> row >> col >> s.x >> s.y;
    }
}