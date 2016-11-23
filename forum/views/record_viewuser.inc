%% views/header.html %%
<h1>{{$title}}</h1>
<div class='display'>
	
    <label>First Name:</label>
    <div class='value'>{{$record['fname']}}</div></br>
    <label>Last Name:</label>
    <div class='value'>{{$record['lname']}}</div></br>
    <label>E-mail:</label>
    <div class='value'>{{$record['email']}}</div></br>
    <label>Password:</label>
    <div class='value'>{{$record['password']}}</div></br>    
    
</div>
<h2>Questions by {{$record['fname']}} {{$record['lname']}}</h2>
<table>
  
  [[ foreach ($questions as $question) : ]]
  <tr>
    <td>
    	  <p><a href="@@forum/view/{{$question['id']}}@@">{{$record['title']}}</a></br>
    	  Posted on: {{$question['datetime']}} by <a href="@@forum/viewuser/{{$question['userid']}}@@">{{$question['fname']}}</a></br>
    	  Filed under: {{$question['tags']}}</br>
    	  {{substr($question['content'],0,45)}}...</p>
    </td>
  </tr>
  [[ endforeach; ]]
</table>

<div class="clearboth">
						    [[if (isLoggedIn()) : ]]
		    <p><a href="@@forum/edit/{{$record['id']}}@@">[Edit]</a>
      ||
      <a href="@@forum/delete/{{$record['id']}}@@">[Delete]</a></p>
    <p><a href="@@index@@"><< Back</a></p>
    [[ endif; ]]
</div>
%% views/footer.html %%