/* Student Name: Mishaal Fadhl
 * Student Number: 991454815
 */

#include "studenttree.h"

Student* make_node(char *name, char *number) {
  Student *new_student;
  new_student = (Student *) malloc(sizeof(Student));
  new_student -> name = (char *) malloc(sizeof(char));
  new_student -> number = (char *) malloc(sizeof(char));
  strcpy (new_student -> name, name);
  strcpy (new_student -> number, number);
  return new_student;
}

/* Given an array of pointers, print the data of the referenced nodes */

/*Function to print out alll the names of the students.*/
void print_array(Student* array_of_students[], int size) {

for (int i = 0; i < size; i++)
{
  printf("%15s%20s\n", array_of_students[i] -> name, array_of_students[i] -> number);
}
}

/* Given a binary tree, print its nodes in inorder*/\
/*Function to print out all students not in the alphabetical order.*/
void print_inorder (Student *node) {
if (node != NULL)
{
  print_inorder(node -> left);
  printf("%15s%20s\n", node -> name, node -> number);
  print_inorder(node -> right);
}
}

/* sort the array -- using selection_sort */
/*Function to print out all students in an alphabetical order.*/
void sort_array (Student** array_of_students, int size) {
int i, j, min;
for (i = 0; i < size - 1; i++)
{
  min = 1;
  for (j = i + 1; j < size; j++)
  if (strcmp(array_of_students[j] -> name, array_of_students[j] -> name) < 0) min = j;
  Student *temp = array_of_students[min];
  array_of_students[min] = array_of_students[i];
  array_of_students[i] = temp;
}
}
/*Function, to create a tree of students to branch out  starting from the left side, the root, then right.*/
Student* make_tree (Student * tree, Student* array_of_students[], int left, int right) {
if (left > right)
return NULL;

int mid = (left + right) / 2;
tree = array_of_students[mid];
tree -> left = make_tree(tree, array_of_students, left, mid -1);
tree -> right = make_tree(tree, array_of_students, mid +1, right);
  return tree;
}

/*Function to delete specific named students from the tree, from when it started, left side, root, then right. */
Student* delete_node(Student* root, char *name) {
  if (root == NULL)
  return root;

  if (strcmp(name, root -> name) <0 ) root -> left = delete_node(root -> left,name);
  else if (strcmp(name, root -> name) > 0 ) root -> right = delete_node(root -> right,name);
  else{
    if (root -> left ==NULL)
    {
      Student *temp = root -> right;
      free(root);
      return temp;
    }
    else if (root -> right == NULL)
    {
    Student *temp = root -> left;
    free(root);
    return temp;
    }
    Student *temp = root -> right;
    while (temp && temp -> left != NULL)
    temp = temp -> left;
    root -> name = temp -> name;
    root -> right = delete_node(root -> right, temp -> name);
  }

  return root;
}

/* 1215_42314 */






































