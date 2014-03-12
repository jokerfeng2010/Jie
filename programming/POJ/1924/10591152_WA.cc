#include <cstdlib>
#include <cctype>
#include <cstring>
#include <string.h>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <queue>
#include <stack>
#include <ctime>
#include <limits.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define clr(x,a) memset(x,a,sizeof(x))
#define sz(x) (int)x.size()
#define see(x) cerr<<#x<<" "<<x<<endl
#define se(x) cerr<<" "<<x 
#define pb push_back
#define mp make_pair
#define getI(n) scanf("%d", &n)
#define getII(n,m) scanf("%d %d", &n,&m)
#define putI(n) printf("%d\n", n)
#define getS(s) scanf("%s", s)
#define F(i,l,r) for (int i=l;i<r;i++)
#define FE(i,l,r) for (int i=l;i<=r;i++)
#define FF(i,r,l) for (int i=r;i>l;i--)
#define FFE(i,r,l) for (int i=r;i>=l;i--)
#define D(i,l,r) ((l<=i)&&(i<=r))
#define bit(x,i) ((x&(1<<i))!=0)
#define abs(x) (x<0?-x:x)
#define ll long long
#define max(a,b) (a<b?b:a)
#define min(a,b) (a<b?a:b)
#define inMap(x,y) (D(x,1,n)&&D(y,1,m))
struct node{
	int x, y;
};
struct node1{
	int x, y, t;
};
int fx[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
char map[103][102][102];
int T, m, n, p, s, sX, sY, eX, eY;
node pos;
vector<node> mPos[101];
bool pan[101][101][101];
bool checkMap(int nT, int xT, int yT){
	if (map[nT][xT][yT] != '.') return false;
	if (xT==eX && yT==eY) return true;
	F(d,0,8)
		if (map[nT][xT+fx[d][0]][yT+fx[d][1]] == 'a') return false;
	return true;
}


bool check(int nT, int xT, int yT){
	if (map[nT][xT][yT] != '.') return false;
	F(d,0,8)
		if (map[nT][xT+fx[d][0]][yT+fx[d][1]] == 'a') return false;
	return true;
}
void printMap(int L, int R){
	FE(k,L,R){
		FE(i,1,n){
			FE(j,1,m) 
				printf("%c", map[k][i][j]);
			printf("\n");
		}
		printf("\n");
	}
}
void printMa(int t, int x, int y){
	FE(i,1,n){
		FE(j,1,m) if(i==x&&j==y)
			printf("p");
		else printf("%c", map[t][i][j]);
		printf("\n");
	}
	printf("\n");

}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	//freopen("in", "r", stdin);
	char e[101];
	int eN;
	while(getII(n,m), n!=0){
		F(i,0,101) mPos[i].clear();
		FE(i,1,n) getS(map[0][i]+1);
		FE(i,0,n+1) map[0][i][0] = map[0][i][m+1] = '#';
		FE(j,0,m+1) map[0][0][j] = map[0][n+1][j] = '#';
		eN = 0;
		FE(i,1,n) FE(j,1,m){
			if (map[0][i][j] == 'p') sX=i, sY=j, map[0][i][j]='.';
			else if (map[0][i][j] == 't') eX=i, eY=j, map[0][i][j]='.';
			else if (map[0][i][j] == 'a' || map[0][i][j] == 'n'){
				e[eN++] = map[0][i][j];
				map[0][i][j]='.';
			}
		}	
		getI(p);
		F(i,0,p){
			getI(s);
			F(j,0,s){
				getII(pos.x,pos.y);
				mPos[i].push_back(pos);
			}
		}
		int k ;
		F(t,1,103)
			memcpy(map[t], map[t-1], sizeof(char)*102*102);
			
		F(t,0,103){
			F(i,0,p){
				k = t % mPos[i].size();
				map[t][mPos[i][k].x][mPos[i][k].y] = e[i];
			}
		}
//		if (map[1][sX][sY] != '.'){
//			printf("impossible\n\n");
//			continue;
//		}
		clr(pan, 0);
	//printMap(0,20);
			queue<node1> q;
			node1 st, st1;
		st.x = sX, st.y = sY, st.t = 0;
		pan[0][sX][sY] = true;
		q.push(st);
			int minTime = 101, xT, yT, nT;
		while(!q.empty()){
			st = q.front(), q.pop();
			//printMa(st.t, st.x, st.y);
			if (st.x == eX && st.y == eY){
				minTime = st.t;
				break;
			}
			if (st.t == 100) continue;
			nT = st.t+1;
			if (!check(nT,st.x,st.y)) continue;

			if (checkMap(nT, st.x, st.y) && !pan[nT][st.x][st.y]){
				pan[nT][st.x][st.y] = true;
				st1.x=st.x, st1.y=st.y, st1.t=nT;
				q.push(st1);
			}

			F(d,0,8){
				xT = st.x + fx[d][0], yT = st.y + fx[d][1];
				if (inMap(xT,yT) && checkMap(nT,xT,yT) && !pan[nT][xT][yT]){
					pan[nT][xT][yT] = true;
					st1.x=xT, st1.y=yT, st1.t=nT;
					q.push(st1);
				}
				if (inMap(xT,yT) && checkMap(nT,xT,yT)){
					xT += fx[d][0], yT += fx[d][1];
					if (inMap(xT,yT) && checkMap(nT,xT,yT) && !pan[nT][xT][yT]){
						pan[nT][xT][yT] = true;
						st1.x=xT, st1.y=yT, st1.t=nT;
						q.push(st1);
					}
				}
			}
		}
		if (minTime == 101) printf("impossible\n\n");
		else printf("%d\n\n", minTime);
	}
}








