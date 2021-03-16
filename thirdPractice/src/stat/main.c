#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"

//Создание списка
struct LinkedList {
  char data[512]; //Создание строки
  struct LinkedList *next; //Создание ссылки на следующий узел
};

typedef struct LinkedList *node; //Создание ссылки узла списка

//Создание узла списка
node createNode() {
    node temp; //Объявление узла
    temp = (node)malloc(sizeof(struct LinkedList)); //Выделение памяти под него
    temp->next = NULL; //Ссылка на следующее значение
    return temp; //Возвращение нового узла
}

//Добавление узла
node addNode(node head, char value[512]) {
    node temp, p; //Объявление пары узлов
    temp = createNode(); //Создание превого
    strcpy(temp->data, value); //Копирование данных
    if(head == NULL) {
        head = temp; //Если список пуст то этот элемент станет верхним
    }
    else {
        p = head; //Иначе происходит замена верхнего элемента
        while(p->next != NULL) {
            p = p->next; //Проходка по списку до тех пор, пока p не станет последним элементом (не станет указывать на NULL)
        }
        p->next = temp; //Добавление нового узла в конец
    }
    return head;
}

//Элемент по индексу (отсчёт с 0)
node NodeByIndex(int index, node head) {
  node n = head;
  for(size_t i = 0; i < index; i++) {
    n = n->next;
  }
  return n;
}

//Удаление элемента по индексу
node DelByIndex(int index, node head)
{
  if (index <= 0) return head;
  if (index == 1 && head->next != NULL) return head->next;
  NodeByIndex(index-1, head)->next = NodeByIndex(index+1, head);
  return head;
}

//Замена одного на другое
void crackEnt(char *str, int mod) {
	if(mod == 1) {
		for (size_t i = 0; i < 512; i++) {
	      if (str[i] == '\n') {
	        str[i] = ';';
	        strcat(str, " ");
	        break;
	      }	
	    }
	}
	else if(mod == -1) {
		for (size_t i = 0; i < 512; i++) {
	      if (str[i] == '\n') {
	        str[i] = '\0';
	        break;
	      }	
	    }	
	}
}

void main() {
  node head = createNode();
  char string1[512];
  char string2[512];
  char string3[512];
  char string4[512];
  char string5[512];
  char string6[512];
  char file[512];
  int check = 1;
  int countNode = 0;
  while (check == 1) {
    printf("Выберете необходимую функцию:\n\n1. Добавить\n2. Удалить\n3. Изменить\n4. Вывести список\n5. Загрузить\n6. Сохранить\n7. Выйти\n\n");

    char p = getchar ();
    while(p == '\n'){
      p = getchar ();
    }
    switch (p) {
      //Добавить
      case '1':
      {
        getchar();
        printf("\nВведите дату: ");
        fgets(string1, 512, stdin);
        printf("Введите время: ");
        fgets(string2, 512, stdin);
        printf("Введите кинотеатр: ");
        fgets(string3, 512, stdin);
        printf("Введите фильм: ");
        fgets(string4, 512, stdin);
        printf("Введите номер зала: ");
        fgets(string5, 512, stdin);
        printf("Выберите тип сеанса:\n\n1. 3D\n2. IMAX\n3. Обычный\n\n");
        switch (getchar()) {
          case '1':
            strcpy(string6, "3D");
            break;
          case '2':
            strcpy(string6, "IMAX");
            break;
          case '3':
            strcpy(string6, "Обычный");
            break;
        }
        for (size_t i = 0; i < 512; i++) {
          if (string1[i] == '\n') {
            string1[i] = ' ';
            break;
          }
        }
        for (size_t i = 0; i < 512; i++) {
          if (string2[i] == '\n') {
            string2[i] = ' ';
            break;
          }
        }
        for (size_t i = 0; i < 512; i++) {
          if (string3[i] == '\n') {
            string3[i] = ' ';
            break;
          }
        }
        for (size_t i = 0; i < 512; i++) {
          if (string4[i] == '\n') {
            string4[i] = ' ';
            break;
          }
        }
        for (size_t i = 0; i < 512; i++) {
          if (string5[i] == '\n') {
            string5[i] = ' ';
            break;
          }
        }
        strcat(string1, string2);
        strcat(string1, string3);
        strcat(string1, string4);
        strcat(string1, string5);
        strcat(string1, string6);
        printf("\n%s\n\n", string1);
        addNode(head, string1);
        countNode++;
        }
        break;
      //Удалить
      case '2':
        {
        int i = 0;
        printf("Выберите элемент: ");
	    scanf("%d", &i);
        while(i > countNode || i < 1) {
	      printf("Невозможный ввод, повторите попытку: ");
	      scanf("%d", &i);
    	}
        head = DelByIndex(i, head);
        countNode--;
        }
        break;
      //Изменить
      case '3':
      printf("\nВведите номер записи: ");
      int x = 0;
      scanf("%d", &x);
      getchar ();
      printf("\nВведите дату: ");
      fgets(string1, 512, stdin);
      printf("Введите время: ");
      fgets(string2, 512, stdin);
      printf("Введите кинотеатр: ");
      fgets(string3, 512, stdin);
      printf("Введите фильм: ");
      fgets(string4, 512, stdin);
      printf("Введите номер зала: ");
      fgets(string5, 512, stdin);
      printf("Выберите тип сеанса:\n\n1. 3D\n2. IMAX\n3. Обычный\n\n");
      switch (getchar()) {
        case '1':
          strcpy(string6, "3D");
          break;
        case '2':
          strcpy(string6, "IMAX");
          break;
        case '3':
          strcpy(string6, "Обычный");
          break;
      }
      for (size_t i = 0; i < 512; i++) {
        if (string1[i] == '\n') {
          string1[i] = ' ';
          break;
        }
      }
      for (size_t i = 0; i < 512; i++) {
        if (string2[i] == '\n') {
          string2[i] = ' ';
          break;
        }
      }
      for (size_t i = 0; i < 512; i++) {
        if (string3[i] == '\n') {
          string3[i] = ' ';
          break;
        }
      }
      for (size_t i = 0; i < 512; i++) {
        if (string4[i] == '\n') {
          string4[i] = ' ';
          break;
        }
      }
      for (size_t i = 0; i < 512; i++) {
        if (string5[i] == '\n') {
          string5[i] = ' ';
          break;
        }
      }
      strcat(string1, string2);
      strcat(string1, string3);
      strcat(string1, string4);
      strcat(string1, string5);
      strcat(string1, string6);
      printf("\n%s\n\n", string1);
      strcpy(NodeByIndex(x, head)->data, string1);
        break;
      //Вывести список
      case '4':
        {
          node n = head;
          n = n->next;
          int i = 1;
          while (n != NULL) {
            printf("%d. %s\n",i++ , n->data);
            n = n->next;
          }
          printf("\n");
        }
        break;
      //Загрузить
      case '5':
        countNode = 0;
      	printf("Введите имя файла без расширения: ");
      	fgets(file, 512, stdin);
      	crackEnt(file, -1);
      	strcat(file, ".bd");

      	FILE *fp2 = fopen(file, "rt"); //Чтение из файлов
      	
      	char str[512];
      	while(fgets(str, 512, fp2) != NULL){
      		addNode(head, str);
      		countNode++;
      	}

      	fclose(fp2);
      	printf("\n");
      	break;
      //Сохранить
      case '6':
      	printf("Введите имя файла без расширения: ");
      	fgets(file, 512, stdin);
      	crackEnt(file, -1);
      	strcat(file, ".bd");

      	FILE *fp = fopen(file, "a+t"); //Файл открывается для записи (и создаётся, если его не существует)
      	
      	if(head->data != "") {
      		node temp = head;
      		while(temp->next != NULL) {
      			fputs(temp->data, fp);
      			temp = temp->next;
      		}
      		fputs(temp->data, fp);
      	}
      	fclose(fp);
      	printf("\n");
      	break;
      //Выйти
      case '7':
        return;
        break;
    }
  }
}
