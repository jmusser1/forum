<?php
include_once "include/util.inc";
include_once "models/forum_model.inc";

// This is the forum RECORDS CONTROLLER...

// Handles the home page...
// Display a list of records...
function safeParam($arr, $index, $default) {
    if ($arr && isset($arr[$index])) {
        return $arr[$index];
    }
    return $default;
}

function get_list($params) {
	// handles the /forum/list url
	
    $records = model_findAllRecords();

    renderTemplate(
        "views/record_list.inc",
        array(
            'title' => 'My Questions and Answer Forum',
            'records' => $records
        )
    );
}

function get_add($params) {
	// handles the /forum/add url
	
    renderTemplate(
        "views/record_add.inc",
        array(
            'title' => 'Add a question',
        )
    );
}

// Handles viewing one individual record...
function get_view($params) {
	// handles the /forum/view/# url, where # is passed as $params[0]
		    ensureLoggedIn();
    $id = safeParam($params, 0, false);
    if ($id === false) {
        die("No Record selected");
    }

    $record = model_findRecordByID($id);
    if (!$record) {
        die("No record with id $id found.");
    }

    renderTemplate(
        "views/record_view.inc",
        array(
            'title' => 'View Question',
            'record' => $record
        )
    );
}


// Handles loading record edit form view...
function get_edit($params) {
	// handles the /forum/edit/# url, where # is passed as $params[0]
	
    $id = safeParam($params, 0, false);
    if (!$id) {
        die("No record specified");
    }

    $record = model_findRecordByID($id);
    if (!$record) {
        die("No record found.");
    }

    renderTemplate(
        "views/record_edit.inc",
        array(
            'title' => 'Edit a question',
            'record' => $record
        )
    );
}


// function to validate whether elements have been provided in $_POST....
function validate_present($elements) {
    $errors = '';
    foreach ($elements as $element) {
        if (!isset($_POST[$element]) || empty($_POST[$element])) {
            $errors .= "Missing $element<br />\n";
        }
    }
    return $errors;
}


// Handles adding a new record with 3 fields...
function post_add($params) {
	// handles the /forum/add url submitted from the add form.  The form values
	// are passed in the $_POST array.
	
    // Validate that all required parameters are set
    // and theoretically that they are all of correct type....
    $errors = validate_present(array('title', 'content', 'tags'));
    if ($errors) {
        die($errors);
    }
    $title = htmlentities($_POST['title']);
    $content = htmlentities($_POST['content']);
    $tags = htmlentities($_POST['tags']);

    $id = model_addRecord($title, $content, $tags);
    // show them the record they just created...
    redirectRelative("index");
}


// Handle Updating an existing record identified by id...
function post_edit($params) {
	// handles the /forum/edit url submitted from the edit form.  The form values are
	// passed in the $_POST array.
	
    $errors = validate_present(array('id', 'title', 'content', 'tags'));
    if ($errors) {
        die($errors);
    }
    $id = $_POST['id'];
    $title = htmlentities($_POST['title']);
    $content = htmlentities($_POST['content']);
    $tags = htmlentities($_POST['tags']);

    model_updateRecord($id, $title, $content, $tags);
    redirectRelative("index");
}


// Handle a request to delete a record by id...
function get_delete($params) {
	// handles the /forum/delete/# url, where # is passed in $params[0]
	
    $id = safeParam($params, 0, false);
    if (!$id) {
        die("No record specified");
    }

    $record = model_findRecordByID($id);
    if (!$record) {
        die("No record found.");
    }

    model_deleteRecord($id);
    // send focus back to the home page...
    redirectRelative("index");
}
// handles the login form
function get_login($params) {
	// handles the /forum/edit/# url, where # is passed as $params[0]
	    renderTemplate(
        "views/record_login.inc",
        array(
            'title' => 'Login'
            )
    );
}

// handles the register page
function get_register($params) {
	// handles the /forum/edit/# url, where # is passed as $params[0]
	
    renderTemplate(
        "views/record_register.inc",
        array(
            'title' => 'Register'
            )
    );
}

function get_viewuser($params) {
	// handles the /forum/viewuser url
	
    $record = model_findUser($params);
		    renderTemplate(
        "views/record_viewuser.inc",
        array(
            'title' => 'View user',
            'record' => $record
        )
    );
}
?>
