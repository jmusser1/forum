<?php
include_once 'models/db.inc';

// This is the forum RECORDS MODEL...

// Assumes table named 'questions' with fields:
//    id (integer, primary key)
//    title (whatever type)
//    content (whatever type)
//    tags (whatever type)
//    ...

// FINDER FUNCTIONS...

// Function to return all records in questions.  Takes no parameters...
function model_findAllRecords() {
    global $db;

    $sql = 'SELECT questions.id, questions.datetime, questions.title, questions.content, 
    questions.tags, questions.userid, forumuser.fname, forumuser.lname FROM questions INNER JOIN 
    forumuser ON questions.userid=forumuser.userid ORDER BY datetime DESC LIMIT 5';
    $statement = $db -> prepare($sql);
    $statement -> execute();
    return $statement -> fetchAll(PDO::FETCH_ASSOC);
}


// Function to return a single record from questions by record_id....
function model_findRecordByID($id) {
    global $db;

    $sql = "SELECT questions.id, questions.datetime, questions.title, questions.content, 
    questions.tags, questions.userid, forumuser.fname, forumuser.lname FROM questions INNER JOIN 
    forumuser ON questions.userid=forumuser.userid  WHERE questions.id = :id ORDER BY questions.datetime";
    $statement = $db -> prepare($sql);
    $statement -> bindParam(':id', $id);
    $statement -> execute();
    return $statement -> fetch(PDO::FETCH_ASSOC);
}

// Function to return records from questions by user....
function model_findRecordByUser($id) {
    global $db;

    $sql = 'SELECT questions.id, questions.datetime, questions.title, questions.content, 
    questions.tags, questions.userid, forumuser.fname, forumuser.lname FROM questions INNER JOIN 
    forumuser ON questions.userid=forumuser.userid  WHERE questions.userid = :id ORDER BY questions.datetime';
    $statement = $db -> prepare($sql);
    $statement -> bindParam(':id', $id);
    $statement -> execute();
    return $statement -> fetch(PDO::FETCH_ASSOC);
}

function model_findUser($id) {
    global $db;

    $sql = 'SELECT forumuser.fname, forumuser.lname FROM forumuser 
    WHERE forumuser.userid = :id';
    $statement = $db -> prepare($sql);
    $statement -> bindParam(':id', $id);
    $statement -> execute();
    return $statement -> fetch(PDO::FETCH_ASSOC);
}

// forum Add Function...
function model_addRecord($title, $content, $tags, $userid) {
    global $db;

    $sql = 'INSERT INTO questions (title, content, tags, datetime,userid) VALUES (:title, :content, :tags, datetime("now"), 5)';
    $statement = $db -> prepare($sql);
    $statement -> bindParam(':title', $title);
    $statement -> bindParam(':content', $content);
    $statement -> bindParam(':tags', $tags);
					    $statement -> execute();
    return $db -> lastInsertId();
}


// forum Update Function...
function model_updateRecord($id, $title, $content, $tags ) {
    global $db;

    $sql = 'UPDATE questions SET datetime = datetime("now"), title = :title, content = :content, tags = :tags WHERE id = :id';
    $statement = $db -> prepare($sql);
    $statement -> bindParam(':title', $title);
    $statement -> bindParam(':content', $content);
    $statement -> bindParam(':tags', $tags);
    $statement -> bindParam(':id', $id);
    $statement -> execute();
}


// forum Delete Function...
function model_deleteRecord($id) {
    global $db;

    $sql = "DELETE FROM questions WHERE id = :id";
    $statement = $db -> prepare($sql);
    $statement -> bindParam(':id', $id);
    $statement -> execute();
}

?>
