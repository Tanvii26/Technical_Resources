#include <bits/stdc++.h>
using namespace std;

//-------1--------
int fact(int n)
{
    if (n < 2)
        return 1;
    return n * fact(n - 1);
}
//-------2--------
int powLinear(int x, int n)
{
    if (n == 1)
        return x;
    return x * powLinear(x, n - 1);
}
//-------3--------
double powLogarithmic(int x, int n)
{
    if (n == 0)
        return 1;
    double ans;
    if (n > 0)
    {
        double prev = powLogarithmic(x, n / 2);
        ans = prev * prev;
        if (n % 2 != 0)
            ans = ans * x;
    }
    if (n < 0)
    {
        double prev = powLogarithmic(x, n / 2);
        ans = prev * prev;
        if (n % 2 != 0)
            ans = ans / x;
    }
    return ans;
}
//-------4--------
void towOfHanoi(int n, int t1, int t2, int t3)
{
    if (n == 0)
        return;

    towOfHanoi(n - 1, t1, t3, t2);
    cout << n << "  [" << t1 << " ->  " << t2 << "]" << endl;
    towOfHanoi(n - 1, t3, t2, t1);
}
//-------5--------
int maxNum(vector<int> arr, int idx)
{
    if (idx == (arr.size() - 1))
        return arr[idx];
    int maxAbTak = maxNum(arr, idx + 1);
    if (maxAbTak < arr[idx])
    {
        return arr[idx];
    }
    else
        return maxAbTak;
}
//-------6--------
int firstIndex(vector<int> arr, int idx, int val)
{
    if (idx == arr.size())
        return -1;
    if (arr[idx] == val)
        return idx;
    return firstIndex(arr, idx + 1, val);
}
//-------7--------
int lastIndex(vector<int> arr, int idx, int val)
{
    if (idx == arr.size())
        return -1;
    int ansPrev = lastIndex(arr, idx + 1, val);
    if (ansPrev == -1)
    {
        if (arr[idx] == val)
            return idx;
        return ansPrev;
    }
    return ansPrev;
}
//-------8--------
vector<int> allIndices(vector<int> arr, int idx, int key, int found){
    if(idx == arr.size()){
        vector<int> res(found,0);
        return res;
    }
    if(arr[idx] == key){
        vector<int> ans = allIndices(arr,idx+1,key,found+1);
        ans[found] = idx;
        return ans;
    }
    else{
        vector<int> ans = allIndices(arr,idx+1,key,found);
        return ans;
    }
}
//-------9--------
vector<string> getSubsequence(string str)
{
    if (str.length() == 0)
    {
        vector<string> res(1, "");
        return res;
    }
    // subsequence = 2^n -->all possible substrings
    // substring n*(n+1)/2 -->valid & continuous
    char ch = str[0];
    string sub = str.substr(1);
    vector<string> ssprev = getSubsequence(sub);
    vector<string> ans;
    for (auto it : ssprev)
    {
        ans.push_back("" + it);
        ans.push_back(ch + it);
    }
    return ans;
}
//-------10--------
vector<string> keypadCombo(vector<string> pattern, string str)
{
    if (str.length() == 0)
    {
        vector<string> res(1, "");
        return res;
    }
    char ch = str[0];
    string sub = str.substr(1);
    vector<string> prev = keypadCombo(pattern, sub);
    vector<string> ans;
    string combination = pattern[ch - '0'];
    for (int i = 0; i < combination.length(); i++)
    {
        char letter = combination[i];
        for (auto it : prev)
        {
            ans.push_back(letter + it);
        }
    }
    return ans;
}
//-------11--------
vector<string> stairPath(int n)
{ // Nth stair to ground using 1/2/3 steps only
    if (n == 0)
    {
        vector<string> res(1, "");
        return res;
    }
    if (n < 0)
    {
        vector<string> res;
        return res;
    }
    vector<string> oneAtaTime = stairPath(n - 1);
    vector<string> twoAtaTime = stairPath(n - 2);
    vector<string> threeAtaTime = stairPath(n - 3);

    vector<string> resultant;
    for (auto it : oneAtaTime)
    {
        resultant.push_back('1' + it);
    }
    for (auto it : twoAtaTime)
    {
        resultant.push_back('2' + it);
    }
    for (auto it : threeAtaTime)
    {
        resultant.push_back('3' + it);
    }

    return resultant;
}
//-------12--------
vector<string> mazePath(int sourceRow, int sourceCol, int destRow, int destCol)
{
    if (sourceRow == destRow && sourceCol == destCol)
    {
        vector<string> path(1, "");
        return path;
    }
    // one at a time either right OR down no diagonals
    vector<string> horizontal, vertical, finalPath;
    if (sourceRow < destRow)
    {
        vertical = mazePath(sourceRow + 1, sourceCol, destRow, destCol);
    }
    if (sourceCol < destCol)
    {
        horizontal = mazePath(sourceRow, sourceCol + 1, destRow, destCol);
    }
    for (auto it : vertical)
    {
        finalPath.push_back('v' + it);
    }
    for (auto it : horizontal)
    {
        finalPath.push_back('h' + it);
    }
    return finalPath;
}
//-------13--------
vector<string> mazePathWithJumps(int sourceRow, int sourceCol, int destRow, int destCol)
{
    if (sourceRow == destRow && sourceCol == destCol)
    {
        vector<string> path(1, "");
        return path;
    }
    // any no of steps right down or diagonal
    vector<string> horizontal, vertical, diagonal, finalPath;
    // vertical move
    for (int jumpSize = 1; jumpSize <= destRow - sourceRow; jumpSize++)
    {
        vertical = mazePath(sourceRow + jumpSize, sourceCol, destRow, destCol);
        for (auto it : vertical)
        {
            finalPath.push_back("v" + to_string(jumpSize) + it);
        }
    }
    // horizontal move
    for (int jumpSize = 1; jumpSize <= destCol - sourceCol; jumpSize++)
    {
        horizontal = mazePath(sourceRow, sourceCol + jumpSize, destRow, destCol);
        for (auto it : horizontal)
        {
            finalPath.push_back("h" + to_string(jumpSize) + it);
        }
    }
    // diagonal move
    for (int jumpSize = 1; jumpSize <= destCol - sourceCol && jumpSize <= destRow - sourceRow; jumpSize++)
    {
        diagonal = mazePath(sourceRow + jumpSize, sourceCol + jumpSize, destRow, destCol);
        for (auto it : diagonal)
        {
            finalPath.push_back("d" + to_string(jumpSize) + it);
        }
    }
    return finalPath;
}
//-------14--------
void printSubsequence(string ques, string ans)
{ // no vector storage, reduces space complexity
    if (ques.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char ch = ques[0];
    string remaining = ques.substr(1);

    printSubsequence(remaining, ans + "");
    printSubsequence(remaining, ans + ch);
}
//-------15--------
void printKeypadComb(vector<string> pattern, string ques, string ans)
{
    if (ques.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char ch = ques[0];
    string quesRem = ques.substr(1);
    string noEquiv = pattern[ch - '0'];
    for (int i = 0; i < noEquiv.length(); i++)
    {
        char c = noEquiv[i];
        printKeypadComb(pattern, quesRem, ans + c);
    }
}
//-------16--------
void printStairsPath(int n, string pathTravelled)
{
    if (n == 0)
    {
        cout << pathTravelled << endl;
        return;
    }
    if (n < 0)
        return;
    printStairsPath(n - 1, pathTravelled + "1");
    printStairsPath(n - 2, pathTravelled + "2");
    printStairsPath(n - 3, pathTravelled + "3");
}
//-------17--------
void printMazePath(int sr, int sc, int dr, int dc, string path)
{
    if (sr == dr && sc == dc)
    {
        cout << path << endl;
        return;
    }
    if (sr < dr)
    {
        printMazePath(sr + 1, sc, dr, dc, path + "v");
    }
    if (sc < dc)
    {
        printMazePath(sr, sc + 1, dr, dc, path + "h");
    }
}
//-------18--------
void printMazePathWithJump(int sr, int sc, int dr, int dc, string path)
{
    if (sr == dr && sc == dc)
    {
        cout << path << endl;
        return;
    }
    for (int jump = 1; jump <= dr - sr; jump++)
    {
        printMazePathWithJump(sr + jump, sc, dr, dc, path + "v" + to_string(jump));
    }
    for (int jump = 1; jump <= dc - sc; jump++)
    {
        printMazePathWithJump(sr, sc + jump, dr, dc, path + "h" + to_string(jump));
    }
    for (int jump = 1; jump <= dr - sr && jump <= dc - sc; jump++)
    {
        printMazePathWithJump(sr + jump, sc + jump, dr, dc, path + "d" + to_string(jump));
    }
}
//-------19--------
void permutation(string ques, string ans)
{
    if (ques.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    for (int i = 0; i < ques.length(); i++)
    {
        char ch = ques[i];
        string qRem = ques.substr(0, i) + ques.substr(i + 1);
        permutation(qRem, ans + ch);
    }
}
//-------20--------
void printEncodings(string ques, string ans)
{
    // 1 to 26 represented as respective alphabet a to z
    // choice of char 0-9(charAt(0)) or 10-26(substr(0,2))
    if (ques.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    int ch1 = ques[0] - '0';
    int ch12 = stoi(ques.substr(0, 2));
    if (ch1 > 0 && ch1 < 10)
    {
        char code = char('a' + ch1 - 1);
        printEncodings(ques.substr(1), ans + code);
    }
    if (ch12 >= 10 && ch12 <= 26)
    { // agar 2 digits to 01, 02 .. nhi chlega
        char code = char('a' + ch12 - 1);
        printEncodings(ques.substr(2), ans + code);
    }
}
//-------21--------
void floodFill(vector<vector<int>> maze, bool visited[4][3], int row, int col, string path)
{
    if (row < 0 || col < 0 || row >= maze.size() || col >= maze[0].size() || maze[row][col] == 1 || visited[row][col] == true)
    {
        return;
    }
    if (row == maze.size() - 1 && col == maze[0].size() - 1)
    {
        cout << path << endl;
        return;
    }
    visited[row][col] = true;                           //         4X3
    floodFill(maze, visited, row - 1, col, path + "t"); //     0    1   1
    floodFill(maze, visited, row, col - 1, path + "l"); //     0    0   1
    floodFill(maze, visited, row + 1, col, path + "d"); //     1    0   0
    floodFill(maze, visited, row, col + 1, path + "r"); //     0    1   0   possible path: drdrd
}
//-------22--------
void targetSumSubset(vector<int>arr, int givenSum, int subsetSum, int i, string set)
{
    if(subsetSum>givenSum) return;
    if (i == arr.size())
    {

        if (givenSum == subsetSum)
        {
            cout << set <<endl;
        }
        return;
    }
    targetSumSubset(arr, givenSum, subsetSum + arr[i], i + 1, set + to_string(arr[i]) + " ");
    targetSumSubset(arr, givenSum, subsetSum, i + 1, set);
}
//-------23--------
bool isRightPos(vector<vector<int>> chess, int row, int col){
    // check for vertically up 
    for(int i=row-1;i>=0;i--){
        if(chess[i][col]==1) return false;
    }
    // check for diagonal left
    for(int i=row-1,j=col-1; i>=0 && j>=0 ; j--,i--){
        if(chess[i][j]==1) return false;
    }
    // check for diagonal right
    for(int i=row-1,j=col+1; i>=0 && j<=chess.size() ; j++,i--){
        if(chess[i][j]==1) return false;
    }
    return true;
}

void nQueens(vector<vector<int>>chess, int r, string ans){ 
    //only check for ROW (if queen already placed in a row, no possibility in any col of same row)

    if(r == chess.size()){
        cout<<ans<<endl;
        return;
    }

    for(int c=0; c<chess.size(); c++){
        if(isRightPos(chess,r,c)){
            chess[r][c]=1;
            nQueens(chess,r+1,ans + to_string(r) + "-" + to_string(c) + " ");
            chess[r][c]=0;
        }
    }
}
//-------24--------
void display(vector<vector<int>> chess){
    for(auto it:chess){
        for(auto c:it)
            cout<<it[c]<<" ";
    cout<<endl;
    }
}
void knightsTour(vector<vector<int>> &chess, int r, int c, int cnt){
    if(r == 0 || c == 0 || r>=chess.size() || c>=chess.size() || chess[r][c]>0) return;
    else if(cnt == pow(chess.size(),2)){ //entire board covered
        chess[r][c]=cnt;
        display(chess);
        chess[r][c]=0;
        return;
    }
    chess[r][c] = cnt;
    knightsTour(chess,r-2,c+1,cnt+1);
    knightsTour(chess,r-1,c+2,cnt+1);
    knightsTour(chess,r+1,c+2,cnt+1);
    knightsTour(chess,r+2,c+1,cnt+1);
    knightsTour(chess,r+2,c-1,cnt+1);
    knightsTour(chess,r+1,c-2,cnt+1);
    knightsTour(chess,r-1,c-2,cnt+1);
    knightsTour(chess,r-2,c-1,cnt+1);
    chess[r][c] = 0;
}

int main()
{

    /*vector<int> arr = {2, 7, 2, 9, 2};
    int ans;
    ans = lastIndex(arr,0,9);
    cout << ans;

    cout<<res.size();
    vector<string> res = mazePathWithJumps(0, 0, 2, 2);
    for (auto it : res)
    {
        cout << it << endl;
    }
    cout << res.size();

    printSubsequence("abc","");

    vector<string> pattern ={".;", "abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};
    printKeypadComb(pattern,"678","");

    printStairsPath(4,"");

    printMazePathWithJump(1,1,3,3,"");

    permutation("abc","");

    printEncodings("12103","");

    vector<vector<int>> maze={{0,1,1},{0,0,1},{1,0,0},{1,0,0}};
    bool visited[4][3];
    floodFill(maze,visited,0,0,"");

    vector<int> arr = {10, 20, 30, 40, 50};
    targetSumSubset(arr, 70, 0, 0, "");

    vector<vector<int>> chess(5,vector<int>(5,0));
    nQueens(chess,0,"");
    
    knightsTour(chess,2,3,0);

    */
    return 0;
}