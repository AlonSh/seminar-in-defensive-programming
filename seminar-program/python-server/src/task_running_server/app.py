from flask import Flask, request

from task_running_server.actions import add, sub, multiply

app = Flask(__name__)

SUPPORTED_ACTIONS = {
    'add': add,
    'sub': sub,
    'multiply': multiply
}


@app.route('/run_task', methods=['POST'])
def run_task():
    request_data = request.json

    if not request_data:
        return 'Request must contain action and parameters in a JSON object', 400

    action = request_data.get('action', None)

    if not action:
        return 'Request must contain an action field!', 400

    if action not in SUPPORTED_ACTIONS:
        return f'Unknown action type "{action}"!', 400

    if 'a' not in request_data or 'b' not in request_data:
        return 'The arguments of the action, "a" and "b" must be provided in the request!', 400

    a = request_data['a']
    b = request_data['b']

    if not isinstance(a, int) or not isinstance(b, int):
        return f'The arguments of the action, "a" and "b" must be integers, not "{a}","{b}"!', 400

    return str(SUPPORTED_ACTIONS[action](int(a), int(b)))


if __name__ == '__main__':
    app.run(ssl_context='adhoc')
    # app.run(debug=True)
