#include<iostream> 
using namespace std; 

typedef char **HuffmanCode;    //存储二进制码
typedef struct
{ 	//定义叶节点
  char data; 
  int weight; 	
  int parent; 	
  int lchild; 	
  int rchild; }HTNode,*HuffmanTree;

void Select(HuffmanTree l, int n, int &s1, int &s2)    //选出权值最小的两个节点
{
  int j;    
  for(j=1;j<=n;j++)   
  {      
    for (int i = 1; i <= n; i++)    
    {    //找出双亲为0的结点     
	  if (l[i].parent == 0)       
	  {             
	    s1 = i;    //s1初始化为i           
		break;    //找到后退出循环    
	  }    
	}    
	for (int i = 1; i <= n; i++)    
	{    //利用for循环找到权值最小的结点并且该结点的双亲为0    
	  if (l[i].weight < l[s1].weight && l[i].parent == 0)  
	    s1 = i;     
	}     //所有结点中权值第二小的点  
	for (int i = 1; i <= n; i++)   
	{    //找出双亲为0的结点，并且不是s1         
	  if (l[i].parent == 0 && i != s1)      
	  {              
	    s2 = i;    //s2初始化为i            
		break;    //找到一个后退出循环        
			
	  }          
	}     
	for (int i = 1; i <= n; i++)    
	{    //找到所有结点权值第二小的一个，该结点满足不能是s1且双亲是0 
	  if (l[i].weight < l[s2].weight && l[i].parent == 0 && i!= s1)        
	  s2 = i;      
	}
  } 	 
} 
	
void creatlist(HuffmanTree &l,int n)    //创建叶子
{
  int m;
  int i; 
  int S1=0; 
  int S2=0; 
  if(n<=1) 	
  {
    cout<<"输入有误"; return ;
  }
  m=2*n-1;  
  l=new HTNode[m+1]; 
  for(i=1;i<=m;i++) 
  {
    l[i].parent=0;l[i].lchild=0;l[i].rchild=0;
  } 
  for(i=1;i<=n;i++) 
  {
    cout<<"请输入第"<<i<<"字符"<<endl; 
	cin>>l[i].data; cout<<"请输入该字符的权值："<<endl; 
	cin>>l[i].weight;
  } 
  for(i=n+1;i<=m;i++)
  {
    Select(l,i-1,S1,S2); 
	l[S1].parent=i;l[S2].parent=i; 
	l[i].lchild=S1;l[i].rchild=S2; 
	l[i].weight=l[S1].weight+l[S2].weight; 
  }
} 
	
void creatlistcode(HuffmanTree l,HuffmanCode &hc,int n) 
{	
  hc= new char*[n + 1];    //分配储存n个字符编码的编码表空间     
  char *cd = new char[n];    //分配临时存储字符编码的动态空间     
  cd[n - 1] = '\0';    //编码结束    
  for (int i = 1; i <= n; i++)    //逐个求字符编码    
  {         
    int start = n - 1;    //start开始指向最后     
	int c = i;         
	int f = l[c].parent;    //f指向结点c的双亲        
	while (f != 0)    //从叶子结点开始回溯，直到根结点       
	{             
      --start;    //回溯一次，start向前指向一个位置             
	  if (l[f].lchild == c) 
	    cd[start] = '0';    //结点c是f的左孩子，则cd[start] = 0;       
	  else cd[start] = '1';    //否则c是f的右孩子，cd[start] = 1        
	  c = f;             
	  f = l[f].parent;    //继续向上回溯       
	}       
	hc[i] = new char[n - start];    //为第i个字符编码分配空间        
    strcpy(hc[i], &cd[start]);    //把求得编码的首地址从cd[start]复制到HC的当前行中   
  }      
  delete cd; 	 
  cout<<"编码结果："<<endl; 	 
  for(int i=1;i<=n;i++) 	
    cout<<"字符为"<<l[i].data<<"权值为"<<l[i].weight<<"叶子结点的哈夫曼编码为:"<<hc[i]<<endl; 
} 
	
void makecode(HuffmanTree l,int n,HuffmanCode hc) 
{
  int j; 
  int u;
  u=0; 
  char mi; 
  cout<<"请输入要编码的字符："<<endl; 
  cin>>mi; for(j=1;j<=n;j++)    //在树中查找该字符
  {
    while(l[j].data==mi) 
    {
	  cout<<hc[j];    //输出其哈夫曼码
	  getchar();
	  u=1;
	  break;
	}
  } 
  if(u==0)
    cout<<"无此字符"<<endl; 
  getchar(); 
} 
	
void translate(HuffmanTree l,int n) 
{
  int m; 
  int i;
  char a[100];
  m=2*n-1;
  cout<<"请选择您要译码的二进制数:"<<endl; 
  cin>>a;  //输入编码
  for (i= 0;a[i]!='\0';i++)   
  {
    if (a[i] == '0')        
	{
	  m = l[m].lchild;          
	}      
	else if (a[i] == '1')       
	{ 
	  m = l[m].rchild;         
	}      
	if (l[m].lchild==0 && l[m].rchild==0)       
	{             
	  cout<<l[m].data;    //找到后输出         
	  m = 2 * n - 1;            
	 }  
  }    	
  return ; 	
} 

int main() 
{
  int n0; 
  char a[100]; 
  cout<<"请输入一共有多少字符："<<endl; 
  cin>>n0; 
  HuffmanTree(Q); 
  HuffmanCode P;
  creatlist(Q,n0); 
  creatlistcode(Q,P,n0);
  makecode(Q,n0,P); 
  translate(Q,n0); 
  cout<<endl;
  system("pause");
  return 0;
} 
