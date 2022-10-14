# importing flask
from flask import Flask, render_template, request
app = Flask(__name__, template_folder="templates")


# initial route
@app.route("/")
def signin():
    return render_template("SIGNIN.html")