%% views/header.html %%
<h1>{{$title}}</h1>
%% views/errors.html %%
<div class='inputs'>
    <form action="@@register@@" method="post">
        <label for="fname">First name:</label>
        <input type="text" id="fname" name="fname" value="{{isset($fname) ? $fname : ''}}" />
        <label for="lname">Last name:</label>
        <input type="lname" id="lname" name="lname" value="{{isset($lname) ? $lname : ''}}" />
        <label for="email">E-mail address:</label>
        <input type="email" id="email" name="email" value="{{isset($email) ? $email : ''}}" />
        <label for="password">Password:</label>
        <input type="password" id="password" name="password" value="{{isset($password) ? $password : ''}}" />
        <input type="submit" value="Save" />
    <form>
</div>
<p><a href="@@index@@"><< Back</a></p>
%% views/footer.html %%
