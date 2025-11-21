BEGIN TRANSACTION;
CREATE TABLE IF NOT EXISTS Author (
    Author_ID   INT PRIMARY KEY,
    name        VARCHAR(100),
    surname     VARCHAR(100),
    thirdname   VARCHAR(100)
);
CREATE TABLE IF NOT EXISTS Book (
    Book_ID     INT PRIMARY KEY,
    title       VARCHAR(255),
    year        INT,
    Author_ID   INT REFERENCES Author(Author_ID)
);
CREATE TABLE IF NOT EXISTS Librarian (
    Librarian_ID INT PRIMARY KEY,
    name         VARCHAR(100),
    surname      VARCHAR(100)
);
CREATE TABLE IF NOT EXISTS Loan (
    Loan_ID      INT PRIMARY KEY,
    Book_ID      INT REFERENCES Book(Book_ID),
    Reader_ID    INT REFERENCES Reader(Reader_ID),
    BorrowDate   DATE,
    ReturnDate   DATE,
    Librarian_ID INT REFERENCES Librarian(Librarian_ID),
    Status_ID    INT REFERENCES Status(Status_ID)
);
CREATE TABLE IF NOT EXISTS Reader (
    Reader_ID   INT PRIMARY KEY,
    name        VARCHAR(100),
    surname     VARCHAR(100)
);
CREATE TABLE IF NOT EXISTS Status (
    Status_ID INT PRIMARY KEY,
    name      VARCHAR(50),
    comment   VARCHAR(255)
);
INSERT INTO "Author" ("Author_ID","name","surname","thirdname") VALUES (1,'Лев','Толстой','Николаевич'),
 (2,'Фёдор','Достоевский','Михайлович');
INSERT INTO "Book" ("Book_ID","title","year","Author_ID") VALUES (1,'Война и мир',1869,1),
 (2,'Преступление и наказание',1866,2);
INSERT INTO "Librarian" ("Librarian_ID","name","surname") VALUES (1,'Анна','Сидорова');
INSERT INTO "Loan" ("Loan_ID","Book_ID","Reader_ID","BorrowDate","ReturnDate","Librarian_ID","Status_ID") VALUES (1,1,1,'2025-02-01','2025-02-15',1,2),
 (2,2,1,'2025-03-10',NULL,1,1),
 (3,1,2,'2025-01-05','2025-01-20',1,2);
INSERT INTO "Reader" ("Reader_ID","name","surname") VALUES (1,'Иван','Иванов'),
 (2,'Пётр','Петров');
INSERT INTO "Status" ("Status_ID","name","comment") VALUES (1,'На руках','Книга ещё не возвращена'),
 (2,'Возвращена','Книга вернулась в библиотеку');
COMMIT;
