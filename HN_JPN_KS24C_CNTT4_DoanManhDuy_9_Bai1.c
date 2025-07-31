#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Employee {
    int id;
    char name[100];
    int age;
    char hometown[100];
    char division[50];
    char phone[20];
}Employee;
//Cap phat bo id tu dong
int countId() {
    static int countID = 1;
    return countID++;
}
//Node Doi
typedef struct DoubleNode {
    Employee data;
    struct DoubleNode *next;
    struct DoubleNode *prev;
}DoubleNode;
//Cap phat bo nho
DoubleNode* createDoubleNode(Employee employee) {
    DoubleNode* newNode = (DoubleNode*)malloc(sizeof(DoubleNode));
    newNode->data = employee;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
//Add
DoubleNode* addDoubleNode(DoubleNode* headDouble, Employee employee) {
    DoubleNode* newNode = createDoubleNode(employee);
    if (headDouble == NULL) return newNode;
    DoubleNode* temp = headDouble;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return headDouble;
}
//Node don
typedef struct Node {
    Employee data;
    struct Node *next;
}Node;
    //cap phat bo nho
Node* createNode(Employee employee) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = employee;
    newNode->next = NULL;
    return newNode;
}
    //Them vao danh sach Case 1
Node* addNode(Node* head, Employee employee) {
    Node* newNode = createNode(employee);
    if (head == NULL) return newNode;
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}
    //case 2
void printNode(Node* head) {
    if (head == NULL) {
        printf("Danh sach trong!\n");
        return;
    }
    Node* temp = head;
    printf("\n-------------------------Danh Sach Nhan Vien-------------------------\n");
    while (temp != NULL) {
        printf("ID: %d\n", temp->data.id);
        printf("Name: %s\n", temp->data.name);
        printf("Age: %d\n", temp->data.age);
        printf("Hometown: %s\n", temp->data.hometown);
        printf("Division: %s\n", temp->data.division);
        printf("Phone: %s\n", temp->data.phone);
        printf("----------------------------------------------------\n");
        temp = temp->next;
    }
}
    //Case 3
Node* deleteNode(Node* head, int valueID) {
        if (head == NULL) {
            printf("Danh sach trong!\n");
            return NULL;
        }
    Node* temp = head;
        if (temp->data.id == valueID) {
            Node* deleteNode = temp;
            temp = temp->next;
            free(deleteNode);
            return temp;
        }else {
            while (temp->next != NULL) {
                if (temp->next->data.id == valueID) {
                    printf("Xoa thanh cong!\n");
                    Node* deleteNode = temp->next;
                    temp->next = temp->next->next;
                    free(deleteNode);
                    return head;
                }
            }
        }
    printf("Khong tim thay sinh vien nay!\n");
    return head;
}
    //Case 4
void updateNode(Node* head, int valueID) {
    if (head == NULL) {
        printf("Danh sach trong!\n");
        return;
    }
    int fount = -1;
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data.id == valueID) {
            printf("-------------------------Nhan Vien Can Tim-----------------------\n");
            printf("ID: %d\n", temp->data.id);
            printf("Name: %s\n", temp->data.name);
            printf("Age: %d\n", temp->data.age);
            printf("Hometown: %s\n", temp->data.hometown);
            printf("Division: %s\n", temp->data.division);
            printf("Phone: %s\n", temp->data.phone);
            printf("----------------------------------------------------\n");

            printf("\n--------------------------Update Nhan Vien-------------------------\n");
            getchar();
            printf("Nhap lai name: ");
            fgets(temp->data.name, 100, stdin);
            temp->data.name[strcspn(temp->data.name, "\n")] = '\0';

            printf("Nhap lai age: ");
            scanf("%d", &temp->data.age);

            getchar();
            printf("Nhap lai Que quan: ");
            fgets(temp->data.hometown, 100, stdin);
            temp->data.hometown[strcspn(temp->data.hometown, "\n")] = '\0';

            printf("Nhap lai phong ban truc thuoc: ");
            fgets(temp->data.division, 50, stdin);
            temp->data.division[strcspn(temp->data.division, "\n")] = '\0';

            printf("Cap nhat thanh cong!\n");
            fount = 1;
        }
        temp = temp->next;
    }
    if (fount == -1) {
        printf("Khong tim thay sinh vien nay!\n");
    }
}
    //Case 5
Node* offNode(Node* head, char* value) {
    if (head == NULL) {
        printf("Danh sach trong!\n");
        return NULL;
    }
    Node* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->data.name, value) == 0) {
            addDoubleNode(head, temp->data);
            printf("Nhan vien nay da di chuyen!\n");
            return head;
        }
        temp = temp->next;
    }
    printf("Khong tim thay nhan vien nay!\n");
    return head;
}
    //Case 6
void sortNode(Node* head) {
    if (head == NULL) {
        printf("Danh sach trong!\n");
        return;
    }
}
int main(){
    int choice;
    Node* head = NULL;
    DoubleNode* headDouble = NULL;
    Employee employee;
    do {
        printf("\n-------------------MENU-------------------\n");
        printf("1. Them moi nhan vien\n");
        printf("2. Hien thi nhan vien\n");
        printf("3. Xoa nhan vien\n");
        printf("4. Cap nhap sinh vien\n");
        printf("5. Di chuyen nhan vien nghi viec\n");
        printf("6. Sap xep nhan vien\n");
        printf("7. Tim kiem nhan vien\n");
        printf("8. Thoat chuong trinh\n");
        printf("-------------------------------------------\n");
        printf("Moi ban lua chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                employee.id = countId();
                printf("ID: %d\n", employee.id);
                getchar();
                printf("Moi ban nhap name: ");
                fgets(employee.name, 100, stdin);
                employee.name[strcspn(employee.name, "\n")] = '\0';
                printf("Moi ban nhap age: ");
                scanf("%d", &employee.age);

                getchar();
                printf("Moi ban nhap Que quan: ");
                fgets(employee.hometown, 100, stdin);
                employee.hometown[strcspn(employee.hometown, "\n")] = '\0';

                printf("Moi ban nhap phong ban truc thuoc: ");
                fgets(employee.division, 50, stdin);
                employee.division[strcspn(employee.division, "\n")] = '\0';

                printf("Moi ban nhap so dien thoai: ");
                fgets(employee.phone, 20, stdin);
                employee.phone[strcspn(employee.phone, "\n")] = '\0';

                head = addNode(head, employee);
                printf("Them moi thanh cong!\n");
                break;
            case 2:
                printNode(head);
                break;
            case 3:
                int deleteID;
                printf("Moi ban nhap ID nhan vien muon xoa: ");
                scanf("%d", &deleteID);
                head = deleteNode(head, deleteID);
                break;
            case 4:
                int searchID;
                printf("Moi ban nhap ID nhan vien muon cap nhat: ");
                scanf("%d", &searchID);
                updateNode(head, searchID);
                break;
            case 5:
                char value[100];
                getchar();
                printf("Moi ban nhap ten nhan vien muon di chuyen: ");
                fgets(value, 100, stdin);
                value[strcspn(value, "\n")] = '\0';

                headDouble = offNode(head, value);
                printf("%s", headDouble->data.name);

                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                printf("Thoat chuong trinh!\n");
                return 1;
            default:
                printf("Lua chon cua ban khong hop le. Vui long lua chon lai!\n");
        }
    }while (choice != 8);
return 0;
}