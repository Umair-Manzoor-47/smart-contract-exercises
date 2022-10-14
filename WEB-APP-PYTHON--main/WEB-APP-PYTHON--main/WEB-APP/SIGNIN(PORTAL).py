# importing flask
from flask import Flask, render_template, request
app = Flask(__name__, template_folder="templates")


# initial route
@app.route("/")
def signin():
    return render_template("SIGNIN.html")

# signup rout


@app.route("/SIGNUP.html")
def signup():
    return render_template("SIGNUP.html")

# route for data comming from signup


@app.route("/signupdata", methods=['POST', 'GET'])
def data_signup():

    email = request.form['email']
    username = request.form['username']
    password = request.form['password']
    sign_up(email, password, username)
    return signin()

# route for data comming from signin


def sign_up(email, password, user_name):
    myfile = open("SIGN.txt", "a")
    record = email+","+user_name+","+password+","
    print(record, file=myfile, sep="\n")
    myfile.close()
    print(" RECORD HAS BEEN ADDED SUESSFULLY .......................")

# function to seperate data from file


def get_field(field, commano):
    commano = int(commano)
    comma_counter = 0
    counter = 0
    diff = commano-1
    temp = ""

    while comma_counter < commano:

        if comma_counter >= diff and comma_counter < commano:
            temp = temp+field[counter]

        if(field[counter+1] == ","):
            comma_counter = comma_counter+1
            counter = counter+1

        counter = counter+1

    return temp

# comparing data entered on webpage and data gained from the file


def sign_in(email, password):
    myfile = open("SIGN.txt", "r")
    record = myfile.read().splitlines()
    myfile.close
    condition = True
    for field in record:
        temp_email = get_field(field, 1)
        tem_password = get_field(field, 3)
        print(tem_password, temp_email)
        if(temp_email == email and tem_password == password):
            return render_template("WELCOME.html")
        else:
            condition = False

    if condition == False:
        return render_template("INVALID.html")


# route for data comming from signin
@app.route("/signindata", methods=['POST', 'GET'])
def data_signin():
    email = request.form['email']
    password = request.form['password']
    condition = sign_in(email, password)
    return condition

# route for welcome (valid) page


@app.route("/WELCOME.html")
def welcome_page():
    return render_template("WELCOME.html")

# route for invalid


@app.route("/INVALID.html")
def USERNOT_FOUND():
    return render_template("INVALID.html")


if __name__ == "__main__":
    app.run(debug=True, host="0.0.0.0")
