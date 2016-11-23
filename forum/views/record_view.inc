%% views/header.html %%
<h1>{{$record['title']}}</h1>
<div class='display'>
    <label>Posted on</label>
    <div class='value'>{{$record['datetime']}}</div></br>
    <label>Files under</label>
    <div class='value'>{{$record['tags']}}</div></br>
    <div class='value'>{{$record['content']}}</div></br>
    
    
    
</div>
<div class="clearboth">
						    [[if (isLoggedIn()) : ]]
		    <p><a href="@@forum/edit/{{$record['id']}}@@">[Edit]</a>
      ||
      <a href="@@forum/delete/{{$record['id']}}@@">[Delete]</a></p>
    <p><a href="@@index@@"><< Back</a></p>
    [[ endif; ]]
</div>
%% views/footer.html %%
