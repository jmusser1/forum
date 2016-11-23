%% views/header.html %%
<h1>{{$title}}</h1>
<div class='inputs'>
    [[if (isLoggedIn()) : ]]
    <form action="@@forum/edit@@" method="post">
        <input type="hidden" id="id" name="id" value="{{$record['id']}}" />
        <label for="title">Title</label>
        <input type="text" id="title" name="title" value="{{$record['title']}}" />
        <label for="content">Content</label>
        <input type="text" id="content" name="content" value="{{$record['content']}}" />
        <label for="tags">Tags</label>
        <input type="text" id="tags" name="tags" value="{{$record['tags']}}" />
        <input type="submit" value="Save" />
    <form>
    	[[ endif; ]]
</div>
<div class="clearboth">
    <p><a href="@@index@@"><< Back</a></p>
</div>
%% views/footer.html %%
