<?php
include_once "include/util.inc";
include_once "models/forum_model.inc";
include_once "controllers/forum.inc";

function get_index($params) {
	// This Handles the /, /index, and /index/index urls.
	
    // redirect to the forum controller get_list() function...
    get_list($params);
}

?>
