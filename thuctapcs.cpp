#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<time.h>
#define MAX 100


void PhatSinhNgauNhien(int a[])
{
	srand(time(0));
	for(int i=0;i<MAX;i++)
	{
		a[i]=(rand()%1500)-750; // ? d�y c�c gi� tr? ng?u nhi�n s? n?m trong do?n [-30,30] .
	}
}

// H�m xu?t m?ng c�c s? nguy�n ng?u nhi�n .
void XuatMang(int a[])
{
	for(int i=0;i<MAX;i++)
	{
		printf("%4d",a[i]);
	}
}

// H�m ho�n v? 2 s? nguy�n.
void HoanVi(int &x,int &y)
{
	int temp=x;
	x=y;
	y=temp;
}


void SapXepGiamDanBangThuatToanQuickSort(int a[],int left,int right)
{
	int i,j,x;
	if(left>=right)
	{
		return;
	}
	x=a[(left+right)/2]; // Ch?n ph?n t? gi?a l�m gi� tr? m?c .
	i=left;
	j=right;
	while(i<j)
	{
		while(a[i]>x) // ? d�y l� s?p gi?m d?n
		{
			i++;
		}
		while(a[j]<x) // ? d�y l� s?p gi?m d?n
		{
			j--;
		}
		if(i<=j)
		{
			HoanVi(a[i],a[j]);
			i++;
			j--;
		}
	}
	SapXepGiamDanBangThuatToanQuickSort(a,left,j);
	SapXepGiamDanBangThuatToanQuickSort(a,i,right);
}


// H�m s?p x?p m?ng c�c s? nguy�n gi?m d?n b?ng thu?t to�n Bubble Sort .
void SapXepGiamDanBangThuatToanBubbleSort(int a[])
{
    for(int i=0;i<MAX-1;i++)
	{
		for(int j=MAX-1;j>i;j--)
		{
			if(a[j]>a[j-1])
			{
				HoanVi(a[j],a[j-1]);
			}
		}
	}
}

// H�m ch�nh .
int main()
{
	quaylai:printf("\n>>>>>>>>>>>>>>>>Chuong Trinh Do Time Cua Cac Thuat Toan Sap Xep:<<<<<<<<<<<<<<\n");
	int a[MAX],b[MAX],c[MAX],d[MAX],tieptuc; // Khai b�o 4 m?ng a,b,c,d ?ng v?i 4 thu?t to�n s?p x?p .
	


	// L?n s?p x?p th? hai - Thu?t To�n Quick Sort .
	int j=1000; 
	clock_t start2 = clock(); 
	while( j--> 0 )
	PhatSinhNgauNhien(b);
	printf("\n>>>>>>>>>>>>>>>Mang Phat Sinh Ngau Nhien Ban Dau Lan 1 La:<<<<<<<<<<<<<<<<<<<<<<<<\n");
	XuatMang(b);
	printf("\n");
	SapXepGiamDanBangThuatToanQuickSort(b,0,MAX-1);
	printf("\n------------Mang Sau Khi Sap Xep Giam Dan Bang Thuat Toan Quick Sort La:------------\n");
	XuatMang(b);
	printf("\n");
	clock_t finish2 = clock(); 
	double duration2 = (double)(finish2 - start2) / CLOCKS_PER_SEC;


	// L?n s?p x?p th? tu - Thu?t To�n Bubble Sort .
	int l=1000; 
	clock_t start4 = clock(); 
	while( l--> 0 )
	PhatSinhNgauNhien(d);
	printf("\n>>>>>>>>>>>>>>>Mang Phat Sinh Ngau Nhien Ban Dau Lan La:<<<<<<<<<<<<<<<<<<<<<<<<\n");
	XuatMang(d);
	printf("\n");
	SapXepGiamDanBangThuatToanBubbleSort(d);
	printf("\n-----------Mang Sau Khi Sap Xep Giam Dan Bang Thuat Toan Bubble Sort La:----------\n");
	XuatMang(d);
	printf("\n");
	clock_t finish4 = clock(); 
	double duration4 = (double)(finish4 - start4) / CLOCKS_PER_SEC;

	printf("\n");
	printf("Thoi gian thuc thi cua thuat toan Quick Sort la: %.2lf", duration2);// Tr? v? th?i gian s?p x?p c?a Thu?t To�n Quick Sort.
	printf("\n");
	printf("Thoi gian thuc thi cua thuat toan Bubble Sort la: %.2lf", duration4);// Tr? v? th?i gian s?p x?p c?a Thu?t To�n Bubble Sort.
	printf("\n");
	printf("\nBan co muon tiep tuc thuc hien chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls"); // X�c nh?n khi ngu?i d�ng b?m ph�m C tr�n b�n ph�m th� x�a di h?t t?t c? nh?ng d? li?u d� th?c thi tru?c d� d? chu?n b? cho l?n th?c thi m?i .
		goto quaylai; 
	}
}
