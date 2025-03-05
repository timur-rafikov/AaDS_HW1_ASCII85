# AaDS_HW1_ASCII85  
Homework: Implementation of the ASCII85 decoder and encoder  
  
## Author  
Рафиков Тимур Ришатович, группа 24.Б81-мм  
## Contacts  
st128186@student.spbu.ru    
@trafikprog  
## Description  
The ASCII85 (base85) decoder and encoder are implemented  
## Build
make
## Usage example
```
$ ascii85    # читает байты из STDIN и выдаёт ASCII85 в STDOUT
$ ascii85 -e # то же самое
$ ascii85 -d # читает ASCII85 из STDIN и выдаёт байты в STDOUT; при ощбке завершается с кодом, отличным от 0
```