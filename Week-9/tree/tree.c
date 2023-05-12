// // 24.04.2023
// // реализовывал Добродомов Захар

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>

// typedef struct t
// {
//     int key;
//     struct t *L;
//     struct t *R;
//     //<_____> d;
// }tree;


// // какая-то техническая белеберда, я хз зачем так себе все усложнять (но может, и скорее всего так и есть, я задачу просто не услышал)
// bool search_t(tree* root, int k, tree*&out_t)
// {
//     bool b = false;
//     out_t = root;

//     if (root != NULL)
//     {
//         do
//         {
//             if (оut_t -> key == k)
//             {
//                 b = true;
//             }
//             else if (out_t -> key < k)
//             {
//                 out_t = out_t -> R;
//             }
//             else
//             {
//                 out_t = out_t -> L;
//             }
//         }
//         while((out_t != NULL) && !b);
//     }
//     return b;
// }

// int main()
// {
//     tree *r;

//     return 0;
// }