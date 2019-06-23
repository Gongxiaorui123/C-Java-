#include<iostream> 
using namespace std; 

typedef char **HuffmanCode;    //�洢��������
typedef struct
{ 	//����Ҷ�ڵ�
  char data; 
  int weight; 	
  int parent; 	
  int lchild; 	
  int rchild; }HTNode,*HuffmanTree;

void Select(HuffmanTree l, int n, int &s1, int &s2)    //ѡ��Ȩֵ��С�������ڵ�
{
  int j;    
  for(j=1;j<=n;j++)   
  {      
    for (int i = 1; i <= n; i++)    
    {    //�ҳ�˫��Ϊ0�Ľ��     
	  if (l[i].parent == 0)       
	  {             
	    s1 = i;    //s1��ʼ��Ϊi           
		break;    //�ҵ����˳�ѭ��    
	  }    
	}    
	for (int i = 1; i <= n; i++)    
	{    //����forѭ���ҵ�Ȩֵ��С�Ľ�㲢�Ҹý���˫��Ϊ0    
	  if (l[i].weight < l[s1].weight && l[i].parent == 0)  
	    s1 = i;     
	}     //���н����Ȩֵ�ڶ�С�ĵ�  
	for (int i = 1; i <= n; i++)   
	{    //�ҳ�˫��Ϊ0�Ľ�㣬���Ҳ���s1         
	  if (l[i].parent == 0 && i != s1)      
	  {              
	    s2 = i;    //s2��ʼ��Ϊi            
		break;    //�ҵ�һ�����˳�ѭ��        
			
	  }          
	}     
	for (int i = 1; i <= n; i++)    
	{    //�ҵ����н��Ȩֵ�ڶ�С��һ�����ý�����㲻����s1��˫����0 
	  if (l[i].weight < l[s2].weight && l[i].parent == 0 && i!= s1)        
	  s2 = i;      
	}
  } 	 
} 
	
void creatlist(HuffmanTree &l,int n)    //����Ҷ��
{
  int m;
  int i; 
  int S1=0; 
  int S2=0; 
  if(n<=1) 	
  {
    cout<<"��������"; return ;
  }
  m=2*n-1;  
  l=new HTNode[m+1]; 
  for(i=1;i<=m;i++) 
  {
    l[i].parent=0;l[i].lchild=0;l[i].rchild=0;
  } 
  for(i=1;i<=n;i++) 
  {
    cout<<"�������"<<i<<"�ַ�"<<endl; 
	cin>>l[i].data; cout<<"��������ַ���Ȩֵ��"<<endl; 
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
  hc= new char*[n + 1];    //���䴢��n���ַ�����ı����ռ�     
  char *cd = new char[n];    //������ʱ�洢�ַ�����Ķ�̬�ռ�     
  cd[n - 1] = '\0';    //�������    
  for (int i = 1; i <= n; i++)    //������ַ�����    
  {         
    int start = n - 1;    //start��ʼָ�����     
	int c = i;         
	int f = l[c].parent;    //fָ����c��˫��        
	while (f != 0)    //��Ҷ�ӽ�㿪ʼ���ݣ�ֱ�������       
	{             
      --start;    //����һ�Σ�start��ǰָ��һ��λ��             
	  if (l[f].lchild == c) 
	    cd[start] = '0';    //���c��f�����ӣ���cd[start] = 0;       
	  else cd[start] = '1';    //����c��f���Һ��ӣ�cd[start] = 1        
	  c = f;             
	  f = l[f].parent;    //�������ϻ���       
	}       
	hc[i] = new char[n - start];    //Ϊ��i���ַ��������ռ�        
    strcpy(hc[i], &cd[start]);    //����ñ�����׵�ַ��cd[start]���Ƶ�HC�ĵ�ǰ����   
  }      
  delete cd; 	 
  cout<<"��������"<<endl; 	 
  for(int i=1;i<=n;i++) 	
    cout<<"�ַ�Ϊ"<<l[i].data<<"ȨֵΪ"<<l[i].weight<<"Ҷ�ӽ��Ĺ���������Ϊ:"<<hc[i]<<endl; 
} 
	
void makecode(HuffmanTree l,int n,HuffmanCode hc) 
{
  int j; 
  int u;
  u=0; 
  char mi; 
  cout<<"������Ҫ������ַ���"<<endl; 
  cin>>mi; for(j=1;j<=n;j++)    //�����в��Ҹ��ַ�
  {
    while(l[j].data==mi) 
    {
	  cout<<hc[j];    //������������
	  getchar();
	  u=1;
	  break;
	}
  } 
  if(u==0)
    cout<<"�޴��ַ�"<<endl; 
  getchar(); 
} 
	
void translate(HuffmanTree l,int n) 
{
  int m; 
  int i;
  char a[100];
  m=2*n-1;
  cout<<"��ѡ����Ҫ����Ķ�������:"<<endl; 
  cin>>a;  //�������
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
	  cout<<l[m].data;    //�ҵ������         
	  m = 2 * n - 1;            
	 }  
  }    	
  return ; 	
} 

int main() 
{
  int n0; 
  char a[100]; 
  cout<<"������һ���ж����ַ���"<<endl; 
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
