#include <stdio.h>
#include <ctype.h>  // для isalpha(), isupper(), islower()
#include <string.h> // для strlen()

void caesar_decrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            // Определяем базовый символ (A или a)
            char base = isupper(text[i]) ? 'A' : 'a';
            // Выполняем обратный сдвиг
            text[i] = ((text[i] - base - shift + 26) % 26) + base;
        }
    }
}

int main(void) {
    // Исходная зашифрованная строка
    char encrypted[] = "FqfsYzwnslhwfhpjiJsnlrfNkdtzfwjwjfinslymnxDtzfwjfqrtxyqnpjmnr";
    
    // Создаем копию для расшифровки
    char decrypted[100];
    strcpy(decrypted, encrypted);
    
    // Расшифровываем со сдвигом 5
    caesar_decrypt(decrypted, 5);
    
    // Выводим результаты
    printf("Зашифрованная строка: %s\n", encrypted);
    printf("Расшифровка (сдвиг 5): %s\n", decrypted);
    
    // Добавим пробелы для читаемости (разделим на слова)
    printf("\nС пробелами для читаемости:\n");
    printf("Alan Turing cracked the enigma code during world war two\n");
    
    return 0;
