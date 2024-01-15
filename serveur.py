from flask import Flask
import pyautogui
import threading
import time

app = Flask(__name__)

# Initial duration for the left click hold
initial_duration = 10
# Variable to store the current duration
current_duration = 0
# Flag to indicate whether a left click action is in progress
left_click_in_progress = False

def simulate_left_click():
    global current_duration, left_click_in_progress
    print('Left click simulation thread started.')
    while True:
        if current_duration > 0:# Simulate a left mouse click and hold at the current position
            # Get the current mouse position
            current_pos = pyautogui.position()
            # Loop to hold the left click for the current duration
            pyautogui.mouseDown(x=current_pos[0], y=current_pos[1], button='left')

            # Set the flag to indicate that a left-click action is in progress
            left_click_in_progress = True
            current_duration -= 1
            print('Left click in progress. Duration remaining: ' + str(current_duration))
        elif current_duration == 0:
            print('Left click simulation complete.')
            # Release the left click
            pyautogui.mouseUp()

            # Reset the flag and duration once the action is complete
            left_click_in_progress = False
            current_duration = -1

@app.route('/click', methods=['GET'])
def click_endpoint():
    global current_duration

    # Set the current duration to the initial duration
    print('Get Left click simulation initiated.')
    current_duration = initial_duration

    return 'Left click simulation initiated.'

if __name__ == "__main__":
    click_thread = threading.Thread(target=simulate_left_click)
    click_thread.start()
    app.run(host='0.0.0.0', port=5000, debug=True)
