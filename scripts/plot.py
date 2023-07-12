import logging
import argparse

"""**********
    MAIN
**********"""
if __name__ == '__main__':
    try:
        parser = argparse.ArgumentParser(
            description='Beautiful description',
            epilog='No epilog')
        parser.add_argument('-s', '--save',
            default=False,
            action="store_true",
            help="Save something")
        parser.add_argument(
            '-l',
            '--loglevel',
            default="INFO",
            type=str,
            required=False,
            options=["ERROR", "WARNING", "INFO", "DEBUG"],
            help="Choose the log level"),
        parser.add_argument('--dryrun', default=False, action='store_true')
        args = parser.parse_args()
        logging.basicConfig(level=args.loglevel)



    except KeyboardInterrupt:
        logging.info('KeyboardInterrupt caught. Performing any cleanup needed')
        exit(0)