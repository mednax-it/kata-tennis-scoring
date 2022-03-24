# 🎾 Tennis Scoring Kata - Python Edition 🐍

## 💻 Setup

Note: this assumes you have a recent-ish version of Python 3 and Poetry both setup locally. Be careful on the Poetry install; right now they're changing their installation process and you want to be sure to [use the new installation process](https://python-poetry.org/docs/master/#installation).

1. [Fork this repo](https://docs.github.com/en/get-started/quickstart/fork-a-repo).
1. Clone your forked repo to your local machine
1. (Optional) Checkout a task branch if you want to leave your `main` in pristine condition for easy resets: `git checkout -b interation1`
1. Install your dependencies: `poetry install`

You should now be ready to code!

Note that all the commands below assume your virtualenv is active. You can either do that by prefixing the command with `poetry run`, e.g., `poetry run ptw`, or you can spawn a shell with the virtualenv activated by running `poetry shell`.

- To run all tests: `pytest`
- To run all tests in watch mode: `ptw`
- To run a specific module of tests: `pytest test/test_tennis_scoring.py`
- To run a specific test: `pytest test/test_tennis_scoring.py::test_start_game` or `pytest test/test_tennis_scoring.py::TestGame::test_start`
