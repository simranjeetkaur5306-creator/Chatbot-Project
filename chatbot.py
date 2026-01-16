import pyttsx3
import pandas as pd
import webbrowser
import wikipedia

# Load Q&A dataset
df = pd.read_csv("c:\\Users\\HP\\Desktop\\chatbot\\Q&A.csv")

# Initialize speech engine
engine = pyttsx3.init()

# Ask question
ques = input("Enter your question: ")

try:
    # If user wants to open something
    if ques.lower().startswith("open"):
        webbrowser.open("https://web.whatsapp.com/")
    
    else:
        # Search in CSV dataset
        df1 = df[df['Question'].str.lower() == ques.lower()]  # case insensitive
        if df1.empty:
            try:
                # If not found, fetch from Wikipedia
                answer = wikipedia.summary(ques, sentences=2)  # short answer
                print("From Wikipedia:", answer)
                engine.say(answer)
            except:
                print("Sorry, I couldn't find anything on Wikipedia.")
                engine.say("Sorry, I couldn't find anything on Wikipedia.")
        else:
            # Found in dataset
            answer = df1['Answer'].iloc[0]
            print("From CSV:", answer)
            engine.say(answer)

    engine.runAndWait()

except Exception as e:
    print("Error:", e)
