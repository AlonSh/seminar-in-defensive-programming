from setuptools import setup, find_packages


setup(
    name="task_running_server",
    version='1.0',
    packages=find_packages(),
    requires=['flask', 'pyopenssl']
)
