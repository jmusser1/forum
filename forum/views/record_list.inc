%% views/header.html %%
<h1>{{$title}}</h1>
<h2>Recent Questions</h2>
<table>
  
  [[ foreach ($records as $record) : ]]
  <tr>
    <td>
    	  <p><a href="@@forum/view/{{$record['id']}}@@">{{$record['title']}}</a></br>
    	  Posted on: {{$record['datetime']}} by <a href="@@forum/viewuser/{{$record['userid']}}@@">{{$record['fname']}}</a></br>
    	  Filed under: {{$record['tags']}}</br>
    	  {{substr($record['content'],0,45)}}...</p>
    </td>
  </tr>
  [[ endforeach; ]]
</table>

<hr />
[[if (isLoggedIn()) : ]]
<p><a href="@@forum/add/@@">Add a question</a></p>
[[ endif; ]]
%% views/footer.html %%
