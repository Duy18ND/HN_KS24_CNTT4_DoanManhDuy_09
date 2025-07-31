#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Folder {
    char name[100];
    struct Floder *left;
    struct Floder *right;
}Folder;
Folder* createFolder(char* name) {
    Folder* root = (Folder*)malloc(sizeof(Folder));
    strcpy(root->name, name);
    root->left = NULL;
    root->right = NULL;
    return root;
}
    //Case 2
Folder* addFolder(Folder* root, char* name) {
    if (root == NULL) {
        return NULL;
    }
    if (root->left == NULL) {
        root->left = createFolder(name);
        return root;
    }else {
        addFolder(root->left, name);
    }
    if (root->right == NULL) {
        root->right = createFolder(name);
    }else {
        addFolder(root->right, name);
    }
}
    //Case 3:
void printFolder(Folder* root) {
    if (root == NULL) {
        return;
    }
    printf("%s\n", root->name);
    printFolder(root->left);
    printFolder(root->right);
}
//Case 5
int heightFolder(Folder* root) {
    if (root == NULL) {
        return 0;
    }
    int left = heightFolder(root->left);
    int right = heightFolder(root->right);
    return left > right ? left + 1 : right + 1;
}
int main() {
    int  choice;
    Folder* root = NULL;

    do {
        printf("-------------------MENU-------------------\n");
        printf("1. Tao thu muc goc\n");
        printf("2. Them thu muc con\n");
        printf("3. In cau cau thu muc\n");
        printf("4. Tim kiem thu muc theo ten\n");
        printf("5. Tinh chieu cao he thong thu muc\n");
        printf("6. In duong dan tu thu muc goc -> thu muc con\n");
        printf("7. Thoat\n");
        printf("-------------------------------------------\n");
        printf("Moi ban lua chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                char name[100];
                getchar();
                printf("Moi ban nhap root: ");
                fgets(name, 100, stdin);
                name[strcspn(name, "\n")] = '\0';
                root = createFolder(name);
                printf("Tao thu muc goc thanh cong!\n");
                printf("%s\n", root);
                break;
            case 2:
                char addName[100];
                printf("Moi ban nhap root: ");
                getchar();
                fgets(name, 100, stdin);
                name[strcspn(name, "\n")] = '\0';
                root = addFolder(root, name);
                break;
            case 3:
                printFolder(root);
                break;
            case 4:
                break;
            case 5:
                printf("Chieu cao he thong thu muc: %d\n", heightFolder(root));
                break;
            case 6:
                break;
            case 7:
                printf("Thoat chuong trinh!\n");
                return 1;
            default:
                printf("Lua chon cua ban khong hop le. Vui long nhap lai!\n");
        }
    }while (choice != 7);
    return 0;
}