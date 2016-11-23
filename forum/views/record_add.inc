%% views/header.html %%
<h1>{{$title}}</h1>
[[if (isLoggedIn()) : ]]
<form action="@@forum/add@@" method="post">
<fieldset>
    <label for="title">Title</label>
    <input type="text" id="title" name="title" /><br />
    <label for="content">Content</label>
    <span></span><input type="text" id="content" name="content" /></span><br />
    <label for="tags">Tags</label>
    <input type="text" id="tags" name="tags" /><br />
    <input type="submit" value="Post" />
</fieldset>
</form>
[[ endif; ]]

%% views/footer.html %%
