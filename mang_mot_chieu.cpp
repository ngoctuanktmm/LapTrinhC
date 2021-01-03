#include <stdio.h>
#define MAX_SIZE    35

void nhapVaoMangMotChieu(int a[], int n){
    /* Hàm này có 2 tham số hình thức
     -  int a[]: cho ta biết cần nhập vào mảng nào.
     -  int n: cho biết số lượng phần tử của mảng cần nhập
     */
    
    int i;
    
    // để thực hiện nhập vào mảng 1 chiều, ta cần sử dụng vòng lặp để nhập hết các phần tử
    // Lưu ý: chỉ số các các phần tử trong mảng được đánh dấu từ 0.
    for(i = 0; i < n; i++){
        // sử dụng lệnh scanf để nhập từng phần tử của mảng
        // phần tử thứ i trong mảng sẽ là a[i]
        scanf("%d", &a[i]);
    }
    
}

void hamDoiCho(int a[], int i, int j){
    /* Hàm này có 3 tham số hình thức
    -  int a[]: cho ta biết cần đổi chỗ phần tử của mảng nào
    -  int i, int j: lần lượt là 2 vị trí cần đổi chỗ cho nhau.
    */
    
    /*
     Để thực hiện việc đổi chỗ, nhớ đến VD về cốc bia và cốc rượu.
     Ta cần khai báo thêm 1 cốc tmp rỗng
     */
    
    int tmp;
    tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void sapXepChon(int a[], int n){
    /*
     Hàm này có 2 tham số hình thức
    -  int a[]: cho ta biết cần sắp xếp mảng nào.
    -  int n: cho biết số lượng phần tử của mảng cần sắp xếp
    */
    
    /*
     Tham kham giải thuật tại:
     -  lý thuyết: https://vi.wikipedia.org/wiki/S%E1%BA%AFp_x%E1%BA%BFp_ch%E1%BB%8Dn
     -  video:  https://visualgo.net/en/sorting?slide=8-1
     */
    
    int i, j, index_min;
    
    // vòng for đầu cho biết chúng ta cần phải sắp xếp n-2 vị trí
    for(i=0; i<n-1; i++)
    {
        index_min = i;
        
        // vòng for thứ 2 thực hiện việc tìm kiếm phần tử nhỏ nhất trong đoạn [i+1 -> n-1]
        for(j=i+1; j<n; j++)
        {
            if(a[j] < a[index_min])
            {
                index_min = j;
            }
        }
        
        /* sau khi thực hiện xong vòng lặp for thứ 2
         cần kiểm tra xem vị trí index_min mới tìm được có phải là vị trí đã gán ban đầu không?
         */
        if (index_min != i)
        {
            // nếu khác thì thực hiện việc đổi chỗ 2 phần tử cho nhau.
            hamDoiCho(a, index_min, i);
        }
        
    }
}

void sapXepNoiBot(int a[], int n){
    /*
     Hàm này có 2 tham số hình thức
    -  int a[]: cho ta biết cần sắp xếp mảng nào.
    -  int n: cho biết số lượng phần tử của mảng cần sắp xếp
    */
    
    /*
    Tham kham giải thuật tại:
    -  lý thuyết: https://vi.wikipedia.org/wiki/S%E1%BA%AFp_x%E1%BA%BFp_n%E1%BB%95i_b%E1%BB%8Dt
    -  video:  https://visualgo.net/en/sorting?slide=7-1
    */
    
    int i, j;
    
    // cơ sở lý thuyết: phần tử nặng (lớn) là phần tử ở cuối mảng
    for(i=n-1; i>0; i--)
    {
        // ta chỉ cần sắp xếp đoạn đầu của mảng từ 0 -> i-1
        for(j=0; j<i; i++)
        {
            // kiểm tra 2 phần tử liên tiếp nhau, nếu phần tử phía trước đang lớn hơn phần tử sau thì đổi chỗ
            if(a[j] > a[j+1])
            {
                hamDoiCho(a, j, j+1);   // thực hiện đổi chô 2 phần tử a[j] và a[j+1]
            }
        }
    }
}

void sapXepChen(int a[], int n){
    /*
     Hàm này có 2 tham số hình thức
    -  int a[]: cho ta biết cần sắp xếp mảng nào.
    -  int n: cho biết số lượng phần tử của mảng cần sắp xếp
    */
    
    /*
    Tham kham giải thuật tại:
    -  lý thuyết: https://vi.wikipedia.org/wiki/S%E1%BA%AFp_x%E1%BA%BFp_ch%C3%A8n
    -  video:  https://visualgo.net/en/sorting?slide=9-1
    */
    
    int i, j;
    // cơ sở lý thuyết: giống việc sắp xếp các quân bài trên tay, tìm từ lá thứ 2 và mang so sánh với lá đầu tiên
    for(i=2; i< n; i++){
        j=i;
        while (a[j] < a[j-1] && j>0) {
            hamDoiCho(a, j, j-1);
            j--;
        }
    }
    
}

void ỉnRaMangMotChieu(int a[], int n){
    /* Hàm này có 2 tham số hình thức
    -  int a[]: cho ta biết cần in ra mảng nào.
    -  int n: cho biết số lượng phần tử của mảng cần in
    */
    
    int i;
    for(i=0; i<n; i++){
        // sử dụng lệnh printf để in tường phần tử của mảng
        // phần tử thứ i trong mảng sẽ là a[i];
        printf("%d", a[i]);
    }
}


int main() {
    int n; // n là số phần tử của mảng
    scanf("%d", &n);
    
    /*
     Có thể sử dụng n để khai báo số lượng phần tử của mảng trong C,
     ngoài ra cũng có thể quan sát đề bài, với những bài cho số lượng phần tử
     của mảng (VD: n<30) thì cứ mạnh dạn định nghĩa #define MAX_SIZE 35.
     Số 35 ở đây là 30+5, bản chất của việc này làm cho chúng ta thao tác không tràn mảng
     
     -  cách khai báo mảng có số phần tử cố định, sử dụng MAX_SIZE là:
        int a[MAX_SIZE];
     -  cách khai báo mảng có số phần tử (n) đã nhập từ bàn phím là:
        int a[n];
     */
    int a[MAX_SIZE];    // mảng nguyên có MAX_SIZE phần tử
    
    // thực hiện gọi hàm nhập vào mảng 1 chiều.
    nhapVaoMangMotChieu(a, n);  // các tham số cần truyền là mảng a, và số phần tử n.
    
    // thực hiện gọi hàm in ra mảng 1 chiều.
    ỉnRaMangMotChieu(a, n);     // các tham số cần truyền là mảng a và số phần tử n.
    
    // Tuỳ từng yêu cầu của đề bài, sẽ sử dụng các thao tác sắp xếp và in ra mảng thích hợp
    
    return 0;
}
