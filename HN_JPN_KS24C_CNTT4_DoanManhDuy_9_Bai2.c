#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Folder {
    char name[100];
    struct Folder *left;
    struct Folder *right;
} Folder;
//Cap phat bo nho
Folder* createFolder(char* name) {
    Folder* root = (Folder*)malloc(sizeof(Folder));
    strcpy(root->name, name);
    root->left = NULL;
    root->right = NULL;
    return root;
}
//case2
Folder* addFolder(Folder* root, char* name) {
    if (root == NULL) {
        printf("Thu muc goc chua duoc tao!\n");
        return NULL;
    }

    if (root->left == NULL) {
        root->left = createFolder(name);
        return root;
    } else if (root->right == NULL) {
        root->right = createFolder(name);
        return root;
    } else {
        addFolder(root->left, name);
        addFolder(root->right, name);
        return root;
    }
}
//case 3
void printFolder(Folder* root) {
    if (root == NULL) {
        return;
    }
    printf("%s\n", root->name);
    printFolder(root->left);
    printFolder(root->right);
}
//case 4
int searchFolderByName(Folder* root, const char* name) {
    if (root == NULL) {
        return 0;
    }
    if (strcmp(root->name, name) == 0) {
        return 1;
    }
    if (searchFolderByName(root->left, name)) {
        return 1;
    }
    if (searchFolderByName(root->right, name)) {
        return 1;
    }
    return 0;
}
//case 5
int heightFolder(Folder* root) {
    if (root == NULL) {
        return 0;
    }
    int left = heightFolder(root->left);
    int right = heightFolder(root->right);
    return (left > right ? left : right) + 1;
}

int main() {
    int choice;
    Folder* root = NULL;

    do {
        printf("-------------------MENU-------------------\n");
        printf("1. Tao thu muc goc\n");
        printf("2. Them thu muc con\n");
        printf("3. In cau truc thu muc\n");
        printf("4. Tim kiem thu muc theo ten\n");
        printf("5. Tinh chieu cao he thong thu muc\n");
        printf("6. In duong dan tu thu muc goc -> thu muc con\n");
        printf("7. Thoat\n");
        printf("-------------------------------------------\n");
        printf("Moi ban lua chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char rootName[100];
                printf("Moi ban nhap ten thu muc goc: ");
                getchar();
                fgets(rootName, 100, stdin);
                rootName[strcspn(rootName, "\n")] = '\0';
                root = createFolder(rootName);
                printf("Tao thu muc goc thanh cong: %s\n", root->name);
                break;
            }
            case 2: {
                if (root == NULL) {
                    printf("Vui long tao thu muc goc truoc!\n");
                    break;
                }
                char folderName[100];
                printf("Moi ban nhap ten thu muc con: ");
                getchar();
                fgets(folderName, 100, stdin);
                folderName[strcspn(folderName, "\n")] = '\0';
                root = addFolder(root, folderName);
                printf("Them thu muc con thanh cong!\n");
                break;
            }
            case 3:
                printf("Cau truc thu muc:\n");
                printFolder(root);
                break;
            case 4:
                if (root == NULL) {
                    printf("Vui long tao thu muc goc truoc!\n");
                    break;
                }
                char searchName[100];
                printf("Nhap ten thu muc can tim: ");
                getchar();
                fgets(searchName, 100, stdin);
                searchName[strcspn(searchName, "\n")] = '\0';

                if (searchFolderByName(root, searchName)) {
                    printf("True\n");
                }else {
                    printf("False\n");
                }
                break;
            case 5:
                printf("Chieu cao he thong thu muc: %d\n", heightFolder(root));
                break;
            case 6:
                break;
            case 7:
                printf("Thoat chuong trinh!\n");
                break;
            default:
                printf("Lua chon khong hop le! Vui long nhap lai!\n");
        }
    } while (choice != 7);

    return 0;
}
